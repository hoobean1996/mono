#pragma once

#include <cstdint>
#include <string>
namespace kv {
void encode_fixed8(char *buf, std::uint8_t val);
void encode_fixed32(char *buf, std::uint32_t val);
void encode_fixed64(char *buf, std::uint64_t val);

uint8_t decode_fixed8(const char *data);
uint32_t decode_fixed32(const char *data);
uint64_t decode_fixed64(const char *data);

inline void put_fixed8(std::string &dst, uint8_t val) {
  char buf[sizeof(val)];
  encode_fixed8(buf, val);
  dst.append(buf, sizeof(val));
}
} // namespace kv