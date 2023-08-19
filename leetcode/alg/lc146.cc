// leetcode 146
// LRU Cache

// LRU Cache 的实现
// 1. 双向链表 list<pair<int, int>> dq + unordered_map<int, list<pair<int,
// int>>:iterator> ma;
// LRU的实现其实就是一个双向链表+hashmap
// 在get的时候，如果存在就移动到对头
#include <bits/stdc++.h>

using namespace std;

class LRUCache {
public:
  list<pair<int, int>> dq;
  // 注意到这里的hash表用的结构是 key ->
  unordered_map<int, list<pair<int, int>>::iterator> ma;
  int cap = 0;

  LRUCache(int capacity) { cap = capacity; }

  int get(int key) {
    // 如果存在该元素
    if (ma.count(key) > 0) {
      // LRU是每次命中数据以后都会把数据移动到头节点
      int val = ma[key]->second;
      dq.erase(ma[key]);
      dq.push_front(make_pair(key, val));
      ma[key] = dq.begin();
      return val;
    } else
      return -1;
  }

  void put(int key, int value) {
    // 在put的时候
    // 如果不存在这个值
    if (ma.find(key) == ma.end()) {
      // 如果容量到达上限，那么久需要弹出最后一个位置的元素
      // 同时更新hashmap
      if (dq.size() == cap) {
        int last = (dq.back()).first;
        dq.pop_back();
        ma.erase(last);
      }
    } else
      // 由于在hashmap中删除该元素
      //  那么就不会找到它了
      // 自然而然就会在后续的操作中被淘汰
      dq.erase(ma[key]);

    dq.push_front(make_pair(key, value));
    ma[key] = dq.begin();
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */