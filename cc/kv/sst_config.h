#pragma once

#include <cstdint>
namespace sleek::oxygen {
struct SSTConfig {
  SSTConfig() = delete;
  ~SSTConfig() = delete;

  static constexpr int32_t RESTART_INTERVAL = 16;

  static constexpr int32_t MAX_DATA_BLOCK_SIZE = 4096;
};
} // namespace sleek::oxygen