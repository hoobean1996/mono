#pragma once

#include <cstdint>
#include <functional>

#include "cc/kv/item.h"

namespace kv {

template <typename K, typename V> class Cache {
public:
  typedef std::function<void(const K &key, V *val)> evicitFn;

  explicit Cache(uint32_t cap);
  ~Cache() = default;

  void insert(const K &key, V *val) {}
  void erase(const K &key);
  bool contains(const K &key);
  Item<K, V> get(const K &key);
  void release(const K &key);
  void onEvicit(evicitFn fn);
};
} // namespace kv