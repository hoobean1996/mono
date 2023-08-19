#pragma once

#include "cc/coro/event.h"
#include "cc/coro/socket.h"
#include <experimental/coroutine>
namespace coro {
class [[nodiscard]] accept_awaiter {
public:
  accept_awaiter(socket &listen_socket, socket &&accpeted_socket) noexcept;
  socket await_resume();
  bool await_ready() const noexcept;
  void await_suspend(std::experimental::coroutine_handle<> coroutine);

private:
  socket &listener_socket_;
  socket accepted_socket_;
  event event_;
  std::experimental::coroutine_handle<> coroutine_{nullptr};

  static void on_readable(int fd, short what, void *context) noexcept;
};
} // namespace coro