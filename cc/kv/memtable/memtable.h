#pragma once

#include <string>
#include <string_view>

#include "skiplist.h"
namespace sleek::oxygen {
template <typename Key, typename Value> class SkipList;

class MemTableIterator;
class SSTableBuilder;
class MemTableBuilder;

class MemTable final {
  enum class OpType {
    deletion = 0x1,
    add = 0x2,
    update = 0x3,
  };

public:
  explicit MemTable() {
    ordered_table_ = std::make_shared<SkipList<std::string, std::string>>();
  }
  ~MemTable() = default;
  MemTable(const MemTable &) = delete;
  MemTable &operator=(const MemTable &) = delete;

  void Add(const std::string_view &key, const std::string_view &value);
  void Update(const std::string_view &key, const std::string_view &value);
  void Delete(const std::string_view &key);

  std::optional<std::string> Get(const std::string_view &key);
  void AsSSTL1(const std::string &sst_table_path,
               std::shared_ptr<SSTableBuilder> builder) {
    auto iter = NewIter();
    while (iter->Valid()) {
      builder->add(iter->key(), iter->value());
      iter->next();
    }
    builder->finishSST();
  }

  MemTableIterator *NewIterator();

private:
  void Insert(OpType op_type, const std::string_view &key,
              const std::string_view &value) {
    if (op_type == OpType::add) {
      ordered_table_->insert(key.data(), value.data());
    } else if (op_type == OpType::update) {
      ordered_table_->remove(key.data());
      ordered_table_->insert(key.data(), value.data());
    } else if (op_type == OpType::deletion) {
      if (ordered_table_->contains(key.data())) {
        ordered_table_->remove(key.data());
      }
      ordered_table_->insert(key.data(), "");
    }
  }

private:
  std::shared_ptr<SkipList<std::string, std::string>> ordered_table_;
};
} // namespace sleek::oxygen