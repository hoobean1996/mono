#pragma once

#include <string_view>

#include "cc/kv/options.h"
#include "cc/kv/status.h"

namespace kv {
class DB {
public:
  explicit DB(const Options &options);

  ~DB() = default;

  DB(const DB &) = delete;
  DB &operator=(const DB &) = delete;

  Status Put(const WriteOptions &wopt, const std::string_view &key,
             const std::string_view &value);
  Status Get(const ReadOptions &ropt, const std::string_view &key,
             std::string *ret);
  Status Delete(const WriteOptions &wopt, const std::string_view &key);

  Status Close();
};
} // namespace kv