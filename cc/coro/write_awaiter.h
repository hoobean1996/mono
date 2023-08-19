#pragma once

#include "cc/coro/event.h"
#include "cc/coro/socket.h"
#include <experimental/coroutine>
#include <span>

namespace coro {
class write_awaiter {
public:
  write_awaiter(socket &socket, std::span<const char> data,
                size_t num_written) noexcept;
  void await_resume() const;
  bool await_ready() const noexcept { return num_written_ == data_.size(); }
  void await_suspend(std::experimental::coroutine_handle<> coroutine);

private:
  socket &socket_;
  event event_;
  std::span<const char> data_;
  size_t num_written_;
  std::experimental::coroutine_handle<> coroutine_{nullptr};
  std::exception_ptr exception_;

  static void on_writable(int fd, short what, void *context) noexcept;
};
} // namespace coro