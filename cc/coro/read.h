#pragma once

#include "cc/coro/read_awaiter.h"
#include "cc/coro/socket.h"
#include <span>

namespace coro {
class [[nodiscard]] read_result {
public:
  read_result(socket &socket, std::span<char> data, size_t num_read,
              bool eof) noexcept;
  operator size_t() const noexcept { return num_read_; }
  size_t num_read() const noexcept { return num_read_; }
  bool eof() const noexcept { return eof_; }
  read_awaiter operator co_await() const;

private:
  socket &socket_;
  std::span<char> data_;
  size_t num_read_;
  bool eof_;
};

read_result read(socket &socket, std::span<char> data);
} // namespace coro