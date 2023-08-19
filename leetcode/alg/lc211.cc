// leetcode 211
// Design Add and Search Words Data Structure
// 这道题和朴素的前缀树的区别在于这个支持.匹配任意字符
#include <bits/stdc++.h>

using namespace std;

class TrieNode {
public:
    map<char, TrieNode*> children;
    bool word = false;
    
    TrieNode() {}
};

class WordDictionary {
public:
    TrieNode* trie;
    
    WordDictionary() {
        trie = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = trie;
        for(const char c: word) {
            if (node->children.find(c) == node->children.end()) node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->word = true;
    }
    
    bool search(string word) {
        return _search(word, trie);
    }

    
    bool _search(string word, TrieNode* node) {
        for(int i=0; i<word.length(); i++) {
            // 如果没有找到这个字符，如果是朴素的Trie，直接就返回false了
            // 如果是 .
            // 这个字符由于可能匹配任意字符，所以我们需要遍历所有的子节点
            // 所以需要
            // for (node in children)
            // 注意到字符串这里需要删去前缀已经匹配的部分
            //      _search(word.substr(i+1), node)
            if (node->children.find(word[i]) == node->children.end()) {
                if (word[i] == '.') {
                    for(auto it=node->children.begin(); it != node->children.end(); it++) {
                        if (_search(word.substr(i+1), it->second)) return true;
                    }
                }
                
                return false;
            }
            else {
                node = node->children[word[i]];
            }
        }
        
        return node->word;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */