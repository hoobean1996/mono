#pragma once
#include "cc/coro/accept_awaiter.h"
#include "cc/coro/socket.h"
namespace coro {
// force the caller to handle this result
class [[nodiscard]] accept_result {
public:
  accept_result(socket &listen_socket, socket &&accepted_socket) noexcept;
  operator socket &&() &&;
  accept_awaiter operator co_await() noexcept;

private:
  socket &listen_socket_;
  socket accepted_socket_;
};

accept_result accept(socket &listen_socket);
} // namespace coro