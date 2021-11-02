//
//  Chat.swift
//  imcore-rest
//
//  Created by Eric Rabil on 7/23/20.
//  Copyright © 2020 Eric Rabil. All rights reserved.
//

import Foundation
import IMSharedUtilities
import BarcelonaDB
import IMCore

private let log = Logger(category: "Chat")

public protocol ChatConfigurationRepresentable {
    var id: String { get }
    var readReceipts: Bool { get set }
    var ignoreAlerts: Bool { get set }
    var groupPhotoID: String? { get set }
}

public extension ChatConfigurationRepresentable {
    var configurationBits: ChatConfiguration {
        ChatConfiguration(id: id, readReceipts: readReceipts, ignoreAlerts: ignoreAlerts, groupPhotoID: groupPhotoID)
    }
}

public struct ChatConfiguration: Codable, Hashable, ChatConfigurationRepresentable {
    public var id: String
    public var readReceipts: Bool
    public var ignoreAlerts: Bool
    public var groupPhotoID: String?
}

public protocol ChatDelegate {
    func chat(_ chat: Chat, willSendMessages messages: [IMMessage], fromCreateMessage createMessage: CreateMessage) -> Void
    func chat(_ chat: Chat, willSendMessages messages: [IMMessage], fromCreatePluginMessage createPluginMessage: CreatePluginMessage) -> Void
}

extension IMChatStyle: Codable {
    public init(from decoder: Decoder) throws {
        self.init(rawValue: try RawValue.init(from: decoder))!
    }
    
    public func encode(to encoder: Encoder) throws {
        try rawValue.encode(to: encoder)
    }
}

extension IMChatStyle: Hashable {
    public static func == (lhs: IMChatStyle, rhs: IMChatStyle) -> Bool {
        lhs.rawValue == rhs.rawValue
    }
    
    public func hash(into hasher: inout Hasher) {
        rawValue.hash(into: &hasher)
    }
}

// (bl-api-exposed)
public struct Chat: Codable, ChatConfigurationRepresentable, Hashable {
    /// Useful for adding application-specific behavior, allows you to hook into different APIs on Chat (like sending)
    public static var delegate: ChatDelegate?
    
    public init(_ backing: IMChat) {
        joinState = backing.joinState
        roomName = backing.roomName
        displayName = backing.displayName
        id = backing.id
        participants = backing.recentParticipantHandleIDs
        unreadMessageCount = backing.unreadMessageCount
        messageFailureCount = backing.messageFailureCount
        service = backing.account?.service?.id
        lastMessage = backing.lastFinishedMessage?.description(forPurpose: .conversationList, in: backing, senderDisplayName: backing.lastMessage?.sender._displayNameWithAbbreviation)
        lastMessageTime = (backing.lastFinishedMessage?.time.timeIntervalSince1970 ?? 0) * 1000
        style = backing.chatStyle
        readReceipts = backing.readReceipts
        ignoreAlerts = backing.ignoreAlerts
        groupPhotoID = backing.groupPhotoID
    }
    
    /// Resolves the chat an IMMessage was sent from
    public static func chat(forMessage id: String) -> Promise<Chat?> {
        IMChat.chat(forMessage: id).maybeMap { chat in
            Chat(chat)
        }
    }
    
    public var id: String
    public var joinState: Int64
    public var roomName: String?
    public var displayName: String?
    public var participants: [String]
    public var unreadMessageCount: UInt64
    public var messageFailureCount: UInt64
    public var service: IMServiceStyle?
    public var lastMessage: String?
    public var lastMessageTime: Double
    public var style: IMChatStyle
    public var readReceipts: Bool
    public var ignoreAlerts: Bool
    public var groupPhotoID: String?
    
    mutating func setTimeSortedParticipants(participants: [HandleTimestampRecord]) {
        self.participants = participants
            .map(\.handle_id)
            .filter(self.participants.contains)
    }
    
    /// The underlying IMChat this Chat was created from
    public var imChat: IMChat {
        IMChat.resolve(withIdentifier: id)!
    }
}

// MARK: - Querying
public extension Chat {
    static var allChats: [Chat] {
        IMChatRegistry.shared.allChats.lazy.map(Chat.init(_:))
    }
    
    /// Returns a chat targeted at the appropriate service for a handleID
    static func directMessage(withHandleID handleID: String) -> Chat {
        Chat(IMChatRegistry.shared.chat(for: bestHandle(forID: handleID)))
    }
    
    /// Returns a chat targeted at the appropriate service for a set of handleIDs
    static func chat(withHandleIDs handleIDs: [String]) -> Chat {
        guard handleIDs.count > 0 else {
            preconditionFailure("chat(withHandleIDs) requires at least one handle ID to be non-null return type")
        }
        
        if handleIDs.count == 1 {
            return directMessage(withHandleID: handleIDs.first!)
        } else {
            return Chat(IMChatRegistry.shared.chat(for: homogenousHandles(forIDs: handleIDs)))
        }
    }
}

extension Thread {
    func sync(_ block: @convention(block) @escaping () -> ()) {
        __im_performBlock(block, waitUntilDone: true)
    }
}

// MARK: - Message Sending
public extension Chat {
    func messages(before: String? = nil, limit: Int? = nil, beforeDate: Date? = nil) -> Promise<[Message]> {
        if BLIsSimulation {
            let guids: [String] = imChat.chatItemRules._items().compactMap { item in
                if let chatItem = item as? IMChatItem {
                    return chatItem._item()?.guid
                } else if let item = item as? IMItem {
                    return item.guid
                }
                
                return nil
            }
            
            return IMMessage.messages(withGUIDs: guids, in: self.id).compactMap { message -> Message? in
                message as? Message
            }.sorted(usingKey: \.time, by: >)
        }
        
        log("Querying IMD for recent messages using chat fast-path")
        
        return BLLoadChatItems(withChatIdentifier: self.id, onServices: [.iMessage], beforeGUID: before, limit: limit).compactMap {
            $0 as? Message
        }
    }
}

public extension Chat {
    var participantIDs: BulkHandleIDRepresentation {
        BulkHandleIDRepresentation(handles: participants)
    }

    var participantNames: [String] {
        participants.map {
            Registry.sharedInstance.imHandle(withID: $0)?.name ?? $0
        }
    }
}
