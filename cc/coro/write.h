#pragma once

#include "cc/coro/socket.h"
#include "cc/coro/write_awaiter.h"
#include <span>
namespace coro {
class [[nodiscard]] write_result {
public:
  write_result(socket &socket, std::span<const char> data,
               size_t num_written) noexcept;

  operator size_t() const noexcept { return num_written_; }
  size_t num_written() const noexcept { return num_written_; }
  write_awaiter operator co_await() const noexcept;

private:
  socket &socket_;
  std::span<const char> data_;
  size_t num_written_;
};

write_result write(socket &socket, std::span<const char> data);
} // namespace coro