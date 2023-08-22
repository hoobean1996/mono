//
//  QuorumContext.swift
//  Quorum
//
//  Created by BIN HE on 21/8/23.
//

import Foundation
import Combine

class QuorumContext: ObservableObject {
    @Published private var repo: String
    init(repo: String) {
        self.repo = repo
    }
}
