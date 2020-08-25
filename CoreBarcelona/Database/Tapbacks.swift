//
//  Tapbacks.swift
//  imcore-rest
//
//  Created by Eric Rabil on 8/7/20.
//  Copyright © 2020 Eric Rabil. All rights reserved.
//

import Foundation
import Vapor
import IMCore

struct BulkTapbackRepresentation: Content {
    var representations: [TapbackRepresentation]
}

struct TapbackRepresentation: Content {
    var handle: String
    var chatGroupID: String
    var associatedMessageGUID: String
    var associatedMessageType: Int64
}

struct TapbackResult {
    var associatedMessageGUID: String
    var associatedMessageType: Int
    var handle: IMHandle
    var fromMe: Bool
}

extension DBReader {
    func associatedMessages(with guid: String) -> EventLoopFuture<[Message]> {
        let promise = eventLoop.makePromise(of: [Message].self)

        pool.asyncRead { result in
            switch result {
            case .failure(let error):
                promise.fail(error)
                return
            case .success(let db):
                do {
                    let messages = try RawMessage
                        .select(RawMessage.Columns.guid, RawMessage.Columns.ROWID)
                        .filter(sql: "associated_message_guid = ?", arguments: [guid])
                        .fetchAll(db)
                    
                    Message.messages(withGUIDs: messages.map { $0.guid! }, on: self.eventLoop).cascade(to: promise)
                } catch {
                    print("Failed to resolve chat group IDs for messages with error \(error)")
                    promise.succeed([])
                    return
                }
            }
            
        }
        
        return promise.futureResult
    }
}
