//
//  ChatItem.swift
//  imcore-rest
//
//  Created by Eric Rabil on 7/24/20.
//  Copyright © 2020 Eric Rabil. All rights reserved.
//

import Foundation
import IMCore

public struct DateItem: ChatItem, Hashable {
    public static let ingestionClasses: [NSObject.Type] = [IMDateChatItem.self]
    
    public init(ingesting item: NSObject, context: IngestionContext) {
        self.load(item: item as! IMDateChatItem, chatID: context.chatID)
    }
    
    init(_ item: IMDateChatItem, chatID: String?) {
        self.load(item: item, chatID: chatID)
    }
    
    public var id: String?
    public var chatID: String?
    public var fromMe: Bool?
    public var time: Double?
    public var threadIdentifier: String?
    public var threadOriginator: String?
    
    public var type: ChatItemType {
        .date
    }
}
