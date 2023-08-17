#pragma once

#include <cstdint>
namespace sleek::oxygen {
template <typename K, typename V>
class Item {
 public:
  Item() = default;

 private:
  K key_;
  V* val_;
  int32_t refCount_ = 0;
  uint32_t hashVal_ = 0;
  bool inCache_ = false;
  uint64_t lastAccessTime_ = 0;
};
}  // namespace sleek::oxygen