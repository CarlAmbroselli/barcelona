//
//  IMChat+TimeSortedParticipants.swift
//  CoreBarcelona
//
//  Created by Eric Rabil on 9/18/20.
//  Copyright © 2020 Eric Rabil. All rights reserved.
//

import Foundation
import IMCore

extension Array where Element: Hashable {
    func removingDuplicates() -> [Element] {
        var addedDict = [Element: Bool]()

        return filter {
            addedDict.updateValue(true, forKey: $0) == nil
        }
    }

    mutating func removeDuplicates() {
        self = self.removingDuplicates()
    }
}

public extension IMChat {
    var recentParticipantHandleIDs: [String] {
        ERTimeSortedParticipantsManager.sharedInstance.sortedParticipants(forChat: self.id).including(array: self.participantHandleIDs()).removingDuplicates()
    }
}
