//
//  BLEventBusDelegate.swift
//  BarcelonaMautrixIPC
//
//  Created by Eric Rabil on 6/14/21.
//  Copyright © 2021 Eric Rabil. All rights reserved.
//

import Barcelona
import IMCore

private extension ChatItemOwned {
    var mautrixFriendlyGUID: String {
        "\(chat.service!.rawValue);\(chat.imChat.isGroup ? "+" : "-");\(sender!)"
    }
    
    var chat: Chat {
        Chat.resolve(withIdentifier: chatID)!
    }
}

private extension CBMessageStatusChange {
    var mautrixFriendlyGUID: String? {
        guard let sender = sender else {
            return nil
        }
        
        return "\(message.service ?? "iMessage");\(chat.isGroup ? "+" : "-");\(sender)"
    }
}

public class BLEventHandler: CBPurgedAttachmentControllerDelegate {
    public static let shared = BLEventHandler()
    
    private let fifoQueue = FifoQueue<Void>()
    
    internal func send(_ command: IPCCommand) {
        BLWritePayload(.init(command: command))
    }
    
    @_spi(unitTestInternals) public func receiveTyping(_ chat: String, _ typing: Bool) {
        if let chat = IMChat.resolve(withIdentifier: chat), chat.isSingle, let recipientID = chat.recipient?.id, BLBlocklistController.shared.isSenderBlocked(recipientID) {
            return
        }
        
        send(.typing(.init(chat_guid: Chat.resolve(withIdentifier: chat)!.imChat.blChatGUID, typing: typing)))
    }
    
    @_spi(unitTestInternals) public func unreadCountChanged(_ chat: String, _ count: Int) {
        guard let chat = IMChat.resolve(withIdentifier: chat) else {
            return
        }
        
        if chat.isSingle, let recipientID = chat.recipient?.id, BLBlocklistController.shared.isSenderBlocked(recipientID) {
            return
        }
        
        if chat.unreadMessageCount == 0, let lastMessageID = chat.lastMessage?.id {
            CLInfo("Mautrix", "Read count for chat \(chat.id, privacy: .public): \(chat.unreadMessageCount, privacy: .public)")
            BLWritePayload(.init(id: nil, command: .read_receipt(.init(sender_guid: nil, is_from_me: true, chat_guid: chat.blChatGUID, read_up_to: lastMessageID))))
        }
    }
    
    public func run() {
        CBDaemonListener.shared.chatParticipantsPipeline.pipe { chat, participants in
            
        }
        
        CBDaemonListener.shared.unreadCountPipeline.pipe(unreadCountChanged)
    
        CBDaemonListener.shared.chatNamePipeline.pipe { chat, name in
            
        }
        
        CBDaemonListener.shared.typingPipeline.pipe(receiveTyping)
        
        CBDaemonListener.shared.messageStatusPipeline.pipe { change in
            guard change.type == .read else {
                return
            }
            if let sender = change.sender, BLBlocklistController.shared.isSenderBlocked(sender) {
                return
            }
            BLWritePayload(.init(command: .read_receipt(BLReadReceipt(sender_guid: change.mautrixFriendlyGUID, is_from_me: change.fromMe, chat_guid: change.chat.blChatGUID, read_up_to: change.messageID))))
        }
        
        BLMessageExpert.shared.eventPipeline.pipe { event in
            switch event {
            case .message(let message):
                if let senderID = message.senderID, BLBlocklistController.shared.isSenderBlocked(senderID) {
                    return
                }
                if CBPurgedAttachmentController.shared.enabled {
                    if message.fileTransferIDs.count > 0 {
                        CBPurgedAttachmentController.shared.process(transferIDs: message.fileTransferIDs).then { [message] in
                            BLWritePayload(.init(command: .message(BLMessage(message: message.refresh()))))
                        }
                        return
                    }
                }
                BLWritePayload(.init(command: .message(BLMessage(message: message))))
            case .sent(id: let id, service: let service, chat: let chat, time: _):
                BLWritePayload(.init(command: .send_message_status(BLMessageStatus(sentMessageGUID: id, onService: service, forChatGUID: chat.blChatGUID))))
            case .failed(id: let id, service: let service, chat: let chat, code: let code):
                BLWritePayload(.init(command: .send_message_status(BLMessageStatus(guid: id, chatGUID: chat.blChatGUID, status: .failed, service: service, message: code.localizedDescription, statusCode: code.description))))
            default:
                break
            }
        }
        
        NotificationCenter.default.addObserver(forName: .IMHandleInfoChanged, object: nil, queue: nil) { notification in
            if BMXContactListIsBuilding {
                return
            }
            
            guard let handle = notification.object as? IMHandle else {
                return
            }
            
            BLWritePayload(.init(command: .contact(BLContact.blContact(forHandleID: handle.id))))
        }
        
        NotificationCenter.default.addObserver(forName: .IMNicknameDidChange, object: nil, queue: nil) { notification in
            if BMXContactListIsBuilding {
                return
            }
            
            guard let dict = notification.object as? [AnyHashable: Any], let handleIDs = dict["handleIDs"] as? [String] else {
                return
            }
            
            BLWritePayloads(handleIDs.map(BLContact.blContact(forHandleID:)).map {
                .init(command: .contact($0))
            })
        }
    }
    
    public func purgedTransferFailed(_ transfer: IMFileTransfer) {
        BLWritePayload(.init(id: nil, command: .error(.init(code: "file-transfer-failure", message: "Failed to download file transfer: \(transfer.errorDescription ?? transfer.error.description) (\(transfer.error.description))"))))
    }
}

extension Chat {
    var lastMessageID: String? {
        imChat.lastMessage?.guid
    }
}
