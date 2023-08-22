//
//  QuorumApp.swift
//  Quorum
//
//  Created by BIN HE on 21/8/23.
//

import SwiftUI

@main
struct QuorumApp: App {
    var body: some Scene {
        WindowGroup {
            ContentView()
                .environmentObject(QuorumContext(repo: "https://github.com/google/leveldb.git"))
        }
    }
}
