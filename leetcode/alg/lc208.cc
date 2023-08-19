// leetcode 208
// Implement Trie (Prefix Tree)

// 实现Trie
// 首先我们不采用数组的实现方式，比较晦涩难解
// 我们定义一个TrieNode来组织我们的Trie
// 注意到startWith的实现方式，最后的判断是可能 node->word == true
// (刚刚和前缀相同)  || node->children.size() > 0 以它为前缀
#include <bits/stdc++.h>

using namespace std;

class TrieNode {
public:
  map<char, TrieNode *> children;
  bool word = false;

  TrieNode() {}
};

class Trie {
private:
  TrieNode *root;
  int count;

public:
  Trie() {
    root = new TrieNode();
    count = 0;
  }

  void insert(string word) {
    TrieNode *node = root;
    for (int i = 0; i < word.length(); i++) {
      char c = word[i];
      if (node->children.find(c) == node->children.end()) {
        node->children[c] = new TrieNode();
      }
      node = node->children[c];
    }
    node->word = true;
  }

  bool search(string word) {
    TrieNode *node = root;
    for (int i = 0; i < word.length(); i++) {
      char c = word[i];
      if (node->children.find(c) == node->children.end())
        return false;
      else
        node = node->children[c];
    }
    return node->word;
  }

  bool startsWith(string word) {
    TrieNode *node = root;
    for (int i = 0; i < word.length(); i++) {
      char c = word[i];
      if (node->children.find(c) == node->children.end())
        return false;
      else
        node = node->children[c];
    }

    return node->word || node->children.size() > 0;
  }
};

// 双数组实现的Trie
// Double Array Trie

// Triple Array Trie
// 1. base: base中的每个元素代表Trie上的一个节点
//   对于节点s, base[s] 代表starting index in next和check pool
// 2. next: 提供一个pool,用来分配sparse vector
// 3. check: 和next一起工作，用于标记owner of next

// For a transition from state s to t, which takes character c as the input
// [s] --> c --> [t]
//   check[base[s]+c] = s
//   next[base[s] + c] = t

// Walking:
//   t := base[s] + c
// if check[t]  = s:
//  next state := next[t]
// else
//  fail

// Construction:

/// Double Array Trie
// [s] --> c --> [t]
//   check[base[s] + c] = s
//   base[s] + c = t
//  index[]

// Walking:
