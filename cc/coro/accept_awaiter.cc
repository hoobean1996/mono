#include "cc/coro/accept_awaiter.h"
namespace coro {
accept_awaiter::accept_awaiter(socket &listen_socket,
                               socket &&accepted_socket) noexcept
    : listener_socket_{listen_socket}, accepted_socket_{
                                           std::move(accepted_socket)} {}

bool accept_awaiter::await_ready() const noexcept {
  return accepted_socket_.fd() != -1;
}

socket accept_awaiter::await_resume() {
  if (accepted_socket_.fd() != -1) {
    return socket{std::move(accepted_socket_)};
  }
  int ret = ::accept(listener_socket_.fd(), nullptr, nullptr);
  if (ret == -1) {
    throw std::runtime_error{"accept failed"};
  }
  return {listener_socket_.get_io_context(), ret};
}

void accept_awaiter::await_suspend(
    std::experimental::coroutine_handle<> coroutine) {
  coroutine_ = coroutine;
  event_ = event{listener_socket_.get_io_context(), listener_socket_.fd(),
                 event::what::read, &accept_awaiter::on_readable,
                 static_cast<void *>(this)};
  event_.activate();
}

void accept_awaiter::on_readable(int, short, void *context) noexcept {
  auto &self = *static_cast<accept_awaiter *>(context);
  self.coroutine_.resume();
}
} // namespace coro