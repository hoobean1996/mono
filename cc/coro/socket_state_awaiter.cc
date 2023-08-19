#include "cc/coro/socket_state_awaiter.h"

namespace coro {
socket_state_awaiter::socket_state_awaiter(socket &socket, short what)
    : socket_{socket}, what_{what} {}

short socket_state_awaiter::await_resume() const noexcept {
  return state_what_;
}
void socket_state_awaiter::await_suspend(
    std::experimental::coroutine_handle<> coroutine) {
  coroutine_ = coroutine;
  event_ =
      event{socket_.get_io_context(), socket_.fd(), what_,
            &socket_state_awaiter::on_state_change, static_cast<void *>(this)};
  event_.activate();
}

void socket_state_awaiter::on_state_change(int, short what,
                                           void *context) noexcept {
  auto &self = *static_cast<socket_state_awaiter *>(context);
  self.state_what_ = what;
  self.coroutine_.resume();
}
} // namespace coro