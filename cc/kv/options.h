#pragma once
#include <string>

namespace kv {
struct Options {
  static Options defaultValue() {
    Options defaultOpts;
    defaultOpts.db_dir = "./oxygen_db";
    defaultOpts.wal_dir = "./oxygen_wal";
    defaultOpts.memtable_max_size = 4 * 1024 * 1024;
    defaultOpts.cache_size = 4096;
    defaultOpts.l1_sst_num = 0;
    return defaultOpts;
  }

  std::string db_dir;
  std::string wal_dir;
  size_t memtable_max_size;
  uint32_t cache_size;
  uint32_t l1_sst_num;
};

struct ReadOptions {};
struct WriteOptions {};
} // namespace kv