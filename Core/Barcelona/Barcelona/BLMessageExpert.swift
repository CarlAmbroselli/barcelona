//
//  BLMessageExpert.swift
//  Barcelona
//
//  Created by Eric Rabil on 4/26/22.
//

import Foundation
import IMCore

/// The BLMessageExpert offers a simplified API for monitoring message state events
public class BLMessageExpert {
    public static let shared = BLMessageExpert()
    
    /// A BLMessageEvent is emitted whenever something significant has happened to a message.
    public enum BLMessageEvent: Hashable {
        public enum Name: String, Codable {
            case failed, delivered, read, sending, sent, message
        }
        
        /// The message with the given ID has failed with the given error code.
        case failed(id: String, service: String, chat: IMChat, code: FZErrorType)
        /// The message with the given ID was delivered to the recipient.
        case delivered(id: String, service: String, chat: IMChat, time: Double?)
        /// The message with the given ID was read by the recipient.
        case read(id: String, service: String, chat: IMChat, time: Double?)
        /// The message with the given ID started sending
        case sending(id: String, service: String, chat: IMChat, time: Double?)
        /// The message with the given ID has been sent
        case sent(id: String, service: String, chat: IMChat, time: Double?)
        /// A message has been sent or received.
        case message(Message)
        
        /// The ID of this message
        public var id: String {
            switch self {
            case .failed(id: let id, _, _, _), .delivered(id: let id, _, _, _), .read(id: let id, _, _, _), .sending(id: let id, _, _, _), .sent(id: let id, _,  _, _):
                return id
            case .message(let message):
                return message.id
            }
        }
        
        public var imChat: IMChat {
            switch self {
            case .failed(_, _, let chat, _), .delivered(_, _, let chat, _), .read(_, _, let chat, _), .sending(_, _, let chat, _), .sent(_, _, let chat, _):
                return chat
            case .message(let message):
                return message.imChat
            }
        }
        
        public var service: String {
            switch self {
            case .failed(_, let service, _, _), .delivered(_, let service, _, _), .read(_, let service, _, _), .sending(_, let service, _, _), .sent(_, let service, _, _):
                return service
            case .message(let message):
                return message.service.rawValue
            }
        }
        
        /// The event name of this message
        public var name: Name {
            switch self {
            case .failed: return .failed
            case .delivered: return .delivered
            case .read: return .read
            case .sending: return .sending
            case .sent: return .sent
            case .message: return .message
            }
        }
    }
    
    private let log = Logger(category: "BLMessageExpert")
    
    /// The pipeline where BLMessageExpert sends message events
    public let eventPipeline = CBPipeline<BLMessageEvent>()
    
    public init() {
        CBDaemonListener.shared.messageStatusPipeline.pipe { change in self.queue.async { self.process(change: change) } }
        CBDaemonListener.shared.messagePipeline.pipe { message in self.queue.async { self.process(message: message) } }
        seenMessages.reserveCapacity(100)
    }
    
    private struct BLMessageEventReceipt: Hashable {
        var event: BLMessageEvent
        var counter: Int
    }
    
    private var counter: Int = 0
    private var seenMessages: [String: BLMessageEventReceipt] = [:]
    private let queue: DispatchQueue = DispatchQueue(label: "BLMessageExpert")
    
    private func send(_ event: BLMessageEvent) {
        if seenMessages[event.id]?.event == event {
            return
        }
        seenMessages[event.id] = BLMessageEventReceipt(event: event, counter: counter)
        if seenMessages.count > 100 {
            seenMessages.sorted(usingKey: \.value.counter, by: <).dropLast(100).forEach { key, _ in
                seenMessages.removeValue(forKey: key)
            }
        }
        counter += 1
        eventPipeline.send(event)
    }
    
    private func process(change: CBMessageStatusChange) {
        switch change.type {
        case .notDelivered:
            if change.hasFullMessage {
                process(failedMessageID: change.messageID, service: change.service, chat: change.chat, failureCode: change.message.errorCode)
            } else {
                process(failedMessageID: change.messageID, service: change.service, chat: change.chat)
            }
        case .delivered:
            process(deliveredMessageID: change.messageID, service: change.service, chat: change.chat, time: change.time)
        case .read:
            process(readMessageID: change.messageID, service: change.service, chat: change.chat, time: change.time)
        case .sent:
            send(.sent(id: change.messageID, service: change.service, chat: change.chat, time: change.time))
        default:
            break
        }
    }
    
    private func process(message: Message) {
        if message.failed {
            process(failedMessageID: message.id, service: message.service.rawValue, chat: message.imChat, failureCode: message.failureCode)
            return
        }
        switch message.sendProgress {
        case .sending:
            send(.sending(id: message.id, service: message.service.rawValue, chat: message.imChat, time: message.time))
        default:
            break
        }
        if message.fromMe && !message.isSent {
            return
        }
        send(.message(message))
    }
}

@_spi(messageExpertControlFlow) public extension BLMessageExpert {
    func process(failedMessageID: String, service: String, chat: IMChat, failureCode: FZErrorType) {
        log.warn("Message %@ failed with failure code %@", failedMessageID, failureCode.description)
        send(.failed(id: failedMessageID, service: service, chat: chat, code: failureCode))
    }
}

fileprivate extension BLMessageExpert {
    func process(failedMessageID: String, service: String, chat: IMChat) {
        guard let message = BLLoadIMMessageItem(withGUID: failedMessageID) else {
            log.fault("Failed to process failed message ID %@ because its IMMessageItem could not be loaded", failedMessageID)
            return
        }
        process(failedMessageID: failedMessageID, service: service, chat: chat, failureCode: message.errorCode)
    }
}

fileprivate extension BLMessageExpert {
    func process(deliveredMessageID: String, service: String, chat: IMChat, time: Double?) {
        log.info("Message %@ was delivered at %@", deliveredMessageID, time.map(NSNumber.init(value:)) ?? "null")
        send(.delivered(id: deliveredMessageID, service: service, chat: chat, time: time))
    }
    
    func process(readMessageID: String, service: String, chat: IMChat, time: Double?) {
        send(.read(id: readMessageID, service: service, chat: chat, time: time))
    }
}

extension BLMessageExpert {
    /// A BLMessageObserver scans events for a message until it is cancelled
    public class BLMessageObserver {
        /// Indicates to BLMessageObserver what it should do after invoking the observer callback.
        public enum NextStep {
            /// Continue observing
            case observe
            /// Cancel the observer and teardown this instance
            case stop
        }
        
        /// A closure to the monitoring messageID – this is a closure so that an observer can be created immediately prior to a message being sent.
        public let messageID: () -> String
        private var callback: ((BLMessageEvent) -> NextStep)?
        private var pipeline: CBPipeline<Void>?
        
        public init(id: @autoclosure @escaping () -> String, expert: BLMessageExpert, callback: @escaping (BLMessageEvent) -> NextStep) {
            self.messageID = id
            self.callback = callback
            self.pipeline = expert.eventPipeline.pipe { [self] event in
                guard event.id == self.messageID() else {
                    return
                }
                switch self.callback?(event) {
                case .observe:
                    return
                case .stop, .none:
                    self.pipeline?.cancel()
                    self.pipeline = nil
                }
            }
        }
        
        @_disfavoredOverload
        public convenience init(id: @autoclosure @escaping () -> String, expert: BLMessageExpert, callback: @escaping (BLMessageEvent) -> ()) {
            self.init(id: id(), expert: expert) {
                callback($0)
                return .observe
            }
        }
        
        public convenience init(id: @autoclosure @escaping () -> String, callback: @escaping (BLMessageEvent) -> NextStep) {
            self.init(id: id(), expert: .shared, callback: callback)
        }
        
        public convenience init(id: @autoclosure @escaping () -> String, callback: @escaping (BLMessageEvent) -> ()) {
            self.init(id: id(), expert: .shared, callback: callback)
        }
        
        /// Manually cancels the expert.
        public func cancel() {
            pipeline?.cancel()
            callback = nil
            pipeline = nil
        }
    }
    
    @_disfavoredOverload
    public func observer(forMessage id: @autoclosure @escaping () -> String, callback: @escaping (BLMessageEvent) -> BLMessageObserver.NextStep) -> BLMessageObserver {
        BLMessageObserver(id: id(), expert: self, callback: callback)
    }
    
    public func observer(forMessage id: @autoclosure @escaping () -> String, callback: @escaping (BLMessageEvent) -> Void) -> BLMessageObserver {
        BLMessageObserver(id: id(), expert: self, callback: callback)
    }
}
