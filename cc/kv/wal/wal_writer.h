#pragma once

#include "cc/kv/file/file_writer.h"
#include <memory>
namespace sleek::oxygen {
class FileWriter;
class WalWriter final {
public:
  explicit WalWriter(std::shared_ptr<FileWriter> fw) : fw_(std::move(fw)){};
  ~WalWriter() { fw_->close(); };
  int Write(const std::string_view &log);

private:
  static const int headerSize_ = 8;
  std::shared_ptr<FileWriter> fw_;
};
} // namespace sleek::oxygen