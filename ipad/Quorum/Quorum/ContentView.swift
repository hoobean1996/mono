//
//  ContentView.swift
//  Quorum
//
//  Created by BIN HE on 21/8/23.
//

import SwiftUI

enum FileType {
    case FILE
    case DIRECTORY
}

struct Tree<Value: Hashable>: Hashable {
    let name: Value // directory name or file name
    var children: [Tree]? = nil
    var type: FileType = FileType.FILE
}

let categories: [Tree<String>] = [
    .init(
        name: "src",
        children: [
            .init(name: "node.h"),
            .init(name: "node.cc"),
            .init(name: "tree.h"),
            .init(name: "tree.cc"),
            .init(
                name: "memory",
                children: [
                    .init(name: "node.h"),
                    .init(name: "node.cc")
                ]
            ),
        ],
        type: FileType.DIRECTORY
    ),
    .init(
        name: "tests",
        children: [
            .init(name: "node_test.cc"),
            .init(name: "tree_test.cc"),
        ],
        type: FileType.DIRECTORY
    ),
    .init(
        name: ".github/workflows",
        children: [],
        type: FileType.DIRECTORY
    )
]



struct TextEditorView: View {
    @Binding var selectedFile: String
    
    var body: some View {
        TextEditor(text: $selectedFile)
    }
}

struct FileManagerView: View {
    @Binding var selectedFile: String
    var body: some View {
        List(categories, id: \.name, children: \.children) { node in
            Button(action: {
                print("Clicked on: \(node.name)")
                selectedFile = node.name
            }) {
                Text(node.name).font(.subheadline)
            }
        }.listStyle(SidebarListStyle())
    }
}


struct ContentView: View {
    @EnvironmentObject private var context: QuorumContext
    @State private var selectedFile: String = ""
    
    var body: some View {
        GeometryReader { geometry in
            HStack {
                FileManagerView(selectedFile: $selectedFile)
                    .frame(width: geometry.size.width * 0.2)
                TextEditorView(selectedFile: $selectedFile)
                    .frame(width:  geometry.size.width * 0.7)
            }
            .padding()
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
