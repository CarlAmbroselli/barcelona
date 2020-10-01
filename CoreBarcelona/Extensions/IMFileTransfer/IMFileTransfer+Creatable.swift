//
//  IMFileTransfer+Creatable.swift
//  CoreBarcelona
//
//  Created by Eric Rabil on 9/11/20.
//  Copyright © 2020 Eric Rabil. All rights reserved.
//

import Foundation
import IMCore
import NIO

public extension IMFileTransfer {
    func saveToDatabase(atPath path: String) -> EventLoopFuture<Void> {
        DBReader().insert(fileTransfer: self, path: path)
    }
}
