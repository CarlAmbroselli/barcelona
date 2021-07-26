//
//  CNContact+Identifiable.swift
//  CoreBarcelona
//
//  Created by Eric Rabil on 9/11/20.
//  Copyright © 2020 Eric Rabil. All rights reserved.
//

import Foundation
import Contacts

extension CNContact: Identifiable {
    public var id: String {
        identifier
    }
}
