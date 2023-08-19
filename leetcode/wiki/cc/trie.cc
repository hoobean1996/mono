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