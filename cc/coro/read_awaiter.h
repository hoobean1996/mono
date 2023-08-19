#pragma once
#include "cc/coro/event.h"
#include "cc/coro/socket.h"
#include "cc/coro/task.h"
#include <span>

namespace coro {
class read_awaiter {
public:
  read_awaiter(socket &socket, std::span<char> data, size_t num_read) noexcept;
  void await_resume() const;
  bool await_ready() const noexcept { return num_read_ == data_.size(); }
  void await_suspend(std::experimental::coroutine_handle<> coroutine);

private:
  socket &socket_;
  event event_;
  std::span<char> data_;
  size_t num_read_;
  std::experimental::coroutine_handle<> coroutine_{nullptr};
  std::exception_ptr exception_;
  static void on_readable(int fd, short what, void *context) noexcept;
};
} // namespace coro