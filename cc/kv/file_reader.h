#pragma once

#include <string>
namespace kv {
class FileReader final {
public:
  explicit FileReader(const std::string &path);
  ~FileReader();
  int read(void *buf, int32_t count, int32_t offset = 0) const;

private:
  int fd_;
};
} // namespace kv