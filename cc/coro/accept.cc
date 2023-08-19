#include "cc/coro/accept.h"
#include "cc/coro/accept_awaiter.h"
namespace coro {
accept_result::accept_result(socket &listen_socket,
                             socket &&accepted_socket) noexcept
    : listen_socket_{listen_socket}, accepted_socket_{
                                         std::move(accepted_socket)} {}

accept_result::operator coro::socket &&() && {
  if (accepted_socket_.fd() == -1) {
    throw std::runtime_error{"no socket has accepted"};
  }
  return std::move(accepted_socket_);
}

accept_awaiter accept_result::operator co_await() noexcept {
  return accept_awaiter{listen_socket_, std::move(accepted_socket_)};
}

accept_result accept(socket &listen_socket) {
  int ret = ::accept(listen_socket.fd(), nullptr, nullptr);
  if (ret == -1) {
    throw std::runtime_error{"write failed"};
  }
  return accept_result{listen_socket,
                       socket{listen_socket.get_io_context(), ret}};
}
} // namespace coro