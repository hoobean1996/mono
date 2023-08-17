#pragma once

#include <memory>
#include <optional>
#include <vector>

namespace sleek::oxygen {
template <typename Key, typename Value> class SkipList;

template <typename Key, typename Value> class Node {
  friend class SkipList<Key, Value>;

public:
  Node() = default;
  explicit Node(Key key, Value value) : key_(key), value_(value) {}
  ~Node() = default;
  Key getKey() const { return key_; }
  Value getValue() const { return value_; }

private:
  Key key_;
  Value value_;
  std::vector<Node<Key, Value> *> forward_;
  int nodeLevel_;
};

template <typename Key, typename Value> class SkipList {
public:
  SkipList() {}
  ~SkipList() = default;

  std::optional<Node<Key, Value> *> search(const Key &key) const {
    Node<Key, Value> *node = header_;
    for (int i = level_; i >= 0; --i) {
      while ((node->forward_[i]->key < key)) {
        node = *(node->forward_ + i);
      }
    }
    node = node->forward_[0];
    if (node->key == key) {
      return node;
    }
    return std::nullopt;
  }

  void remove(const Key &key) {}

  bool contains(const Key &key) {}

  bool insert(const Key &key, Value value) {
    Node<Key, Value> *update[MAX_LEVEL];
    Node<Key, Value> *node = header_;
    for (int i = level_; i >= 0; --i) {
      while ((node->forward_[i]->key_ < key)) {
        node = node->forward_[i];
      }
      update[i] = node;
    }
    node = node->forward_[0];
    if (node->key == key) {
      return false;
    }
    int nodeLevel = getRandomLevel();
    if (nodeLevel > level_) {
      nodeLevel = ++level_;
      update[nodeLevel] = header_;
    }
    Node<Key, Value> *newValue;
    createNode(nodeLevel, newValue, key, value);
  }

private:
  void createSkipList(Key footerKey) {
    createNode(0, footer_);
    footer_->key = footerKey;
    this->level_ = 0;
    createNode(MAX_LEVEL, header_);
    for (int i = 0; i < MAX_LEVEL; ++i) {
      header_->forward_[i] = footer_;
    }
    nodeCount_ = 0;
  }
  void freeSkipList() {
    Node<Key, Value> *p = header_;
    Node<Key, Value> *q;
    while (p != nullptr) {
      q = p->forward_[0];
      delete p;
      p = q;
    }
    delete p;
  }
  void createSkipListNode(int level, Node<Key, Value> *&node) {
    node = new Node<Key, Value>(nullptr, nullptr);
    node->forward_ = new Node<Key, Value> *[level + 1];
    node->nodeLevel_ = level;
    assert(node != nullptr);
  }
  void createNode(int level, Node<Key, Value> *&node, Key key, Value value) {
    node = new Node<Key, Value>(key, value);
    if (level > 0) {
      node->forward_ = new Node<Key, Value> *[level + 1];
    }
    node->nodeLevel_ = level;
    assert(node != nullptr);
  }
  int getRandomLevel();

private:
  int level_;
  Node<Key, Value> *header_;
  Node<Key, Value> *footer_;
  size_t nodeCount_;
  static const int MAX_LEVEL = 16;
};

} // namespace sleek::oxygen