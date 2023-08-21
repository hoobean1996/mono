#pragma once
#include <cstdint>
#include <sys/_types/_size_t.h>

namespace kv {

inline uint32_t crc32c(uint32_t crc, const char *buf, size_t len) {
  static uint32_t table[256];
  static bool have_table = false;
  uint32_t rem;

  /* Create lookup table if it doesn't exist */
  if (!have_table) {
    uint32_t poly = 0xEDB88320;
    for (uint32_t i = 0; i < 256; i++) {
      rem = i;
      for (uint32_t j = 0; j < 8; j++) {
        if (rem & 1) {
          rem = (rem >> 1) ^ poly;
        } else {
          rem >>= 1;
        }
      }
      table[i] = rem;
    }
    have_table = true;
  }

  /* Update CRC */
  crc = ~crc;
  for (size_t i = 0; i < len; i++) {
    crc = (crc >> 8) ^ table[(crc & 0xFF) ^ buf[i]];
  }
  return ~crc;
}
} // namespace kv