#include "file_reader.h"
#include <sys/fcntl.h>
#include <sys/unistd.h>
#include <unistd.h>

namespace sleek::oxygen {
FileReader::FileReader(const std::string &path) {
  if (access(path.c_str(), F_OK) != F_OK) {
  } else {
    fd_ = open(path.c_str(), O_RDONLY);
    assert(fd_ >= 0);
  }
}

FileReader::~FileReader() {
  if (fd_ != -1) {
    close(fd_);
    fd_ = -1;
  }
}

int FileReader::read(void *buf, int32_t count, int32_t offset) const {
  if (buf == nullptr) {
  }
  if (fd_ == -1) {
  }
  int cnt = pread(fd_, buf, count, offset);
  if (cnt != count) {
  }
  return 0;
}
} // namespace sleek::oxygen