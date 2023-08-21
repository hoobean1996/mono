#include "cc/kv/data_block_builder.h"

#include <cstdint>

#include "cc/kv/sst_config.h"

namespace kv {
int DataBlockBuilder::add(const std::string &key, const std::string &value) {
  if (key.empty()) {
    return 0;
  }
  bool need_fullkey = false;
  if (recordNum_ % SSTConfig::RESTART_INTERVAL == 0) {
    need_fullkey = true;
    recordGroupOffset_.push_back(static_cast<int32_t>(get_reecords_size()));
  }
  ++recordNum_;
  if (need_fullkey) {
    // utils::PutFixed32(_data, 0);
    // utils::PutFixed32(_data, static_cast<int32_t>(key.size()));
  }
}
} // namespace kv