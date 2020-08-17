//
//  MessageEvents.swift
//  imcore-rest
//
//  Created by Eric Rabil on 8/9/20.
//  Copyright © 2020 Eric Rabil. All rights reserved.
//

import Foundation
import IMCore
import os.log
import NIO

private let IMChatMessageDidChangeNotification = NSNotification.Name(rawValue: "__kIMChatMessageDidChangeNotification")
private let IMChatItemsDidChangeNotification = NSNotification.Name(rawValue: "__kIMChatItemsDidChangeNotification")
private let IMChatMessageReceivedNotification = NSNotification.Name(rawValue: "__kIMChatMessageReceivedNotification")

private let messageKey = "__kIMChatValueKey";
private let IMChatItemsRemoved = "__kIMChatItemsRemoved";
private let IMChatItemsInserted = "__kIMChatItemsInserted";
private let IMChatItemsRegenerate = "__kIMChatItemsRegenerate";
private let IMChatItemsReload = "__kIMChatItemsReload";
private let IMChatItemsOldItems = "__kIMChatItemsOldItems";

private let log_messageEvents = OSLog(subsystem: Bundle.main.bundleIdentifier!, category: "MessageEvents")

let ChangedItemsExclusion = [
//    IMTextMessagePartChatItem.self,
//    IMAttachmentMessagePartChatItem.self,
    IMMessageAcknowledgmentChatItem.self,
    IMAssociatedMessageItem.self,
//    IMMessageStatusChatItem.self,
]

//private let ChangedItemsExclusion = [AnyClass.Type]()

/**
 Tracks events related to IMMessage
 */
class MessageEvents: EventDispatcher {
    override func wake() {
        addObserver(forName: IMChatItemsDidChangeNotification) {
            self.itemsChanged($0)
        }
    }
    
    /**
     Dispatches incoming transcript items
     */
    private func process(inserted items: [NSObject], in chat: IMChat) {
        var messages: [IMMessage] = []
        
        var wrapped = items.compactMap { transcriptItem -> EventLoopFuture<ChatItem?>? in
            os_log("👨🏻‍💻 Processing inserted IMTranscriptItem %@", transcriptItem, log_messageEvents)
            
            switch (transcriptItem) {
            case let item as IMMessagePartChatItem:
                if !messages.contains(item.message) {
                    messages.append(item.message)
                }
                return nil
            default:
                return ERIndeterminateIngestor.ingest(transcriptItem, in: chat.groupID)
            }
        }
        
        messages.forEach {
            wrapped.append(ERIndeterminateIngestor.ingest($0, in: chat.groupID))
        }
        
        EventLoopFuture<ChatItem?>.whenAllSucceed(wrapped, on: eventProcessing_eventLoop.next()).map { $0.compactMap { $0 } }.whenSuccess { chatItems in
            if chatItems.count == 0 {
                return
            }
            
            StreamingAPI.shared.dispatch(eventFor(itemsReceived: BulkChatItemRepresentation(items: chatItems)))
        }
    }
    
    /**
     Receives participant change, group name change, date chat item
     */
    private func itemsChanged(_ notification: Notification) {
        guard let userInfo = notification.userInfo as? [String: NSObject] else { return }
        guard let chat = notification.object as? IMChat else { return }
        guard let oldItems = userInfo[IMChatItemsOldItems] as? [IMChatItem] else { return }
        
        userInfo.forEach {
            guard let set = $0.value as? NSIndexSet else { return }
            
            switch ($0.key) {
            case IMChatItemsRegenerate:
                break;
            case IMChatItemsReload:
                break;
            case IMChatItemsInserted:
                self.process(inserted: set.compactMap { index -> NSObject? in
                    guard let item = chat.chatItems[safe: index] else {
                        os_log("⁉️ Bad index when parsing chat items!", type: .error, log_messageEvents)
                        return nil
                    }
                    
                    return item
                }, in: chat)
                
                break;
            case IMChatItemsRemoved:
                let guids = Array(Set(set.compactMap { index in
                    oldItems[index]._item().guid
                }))
                if guids.count == 0 { return }
                
                StreamingAPI.shared.dispatch(eventFor(itemsRemoved: BulkMessageIDRepresentation(messages: guids)), to: nil)
                
                break;
            default:
                return
            }
        }
    }
}
