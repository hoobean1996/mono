#pragma once
#include <string>

namespace sleek::oxygen {
class FileWriter;

/// DataBlock layout
/// Record_1
/// Record_2
/// ...
/// Record_n
/// Restart_1
/// Restart_2
/// ...
/// Restart_k
/// Restart_Offset

/// 1. [Record_1, Record_n] N records in total
/// Record layout
/// +----------------------------------------------------------------------------------------+
/// |shared_key_len(4b)|unshared_key_len(4b)|value_len(4b)|unshared_key_content|value_content|
/// +----------------------------------------------------------------------------------------+

class DataBlockBuilder final {
  using size_type = std::string::size_type;

 public:
  DataBlockBuilder() = default;
  ~DataBlockBuilder() = default;

  int add(const std::string& key, const std::string& value);
  int finish_data_block();
  std::string_view data() { return data_; }
  void clear();

 private:
  size_t get_reecords_size() const { return data_.size(); }

 private:
  std::vector<int32_t> recordGroupOffset_;
  std::string preKey_;
  std::string data_;
  int32_t recordNum_ = 0;
};
}  // namespace sleek::oxygen