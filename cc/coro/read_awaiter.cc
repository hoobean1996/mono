#include "cc/coro/read_awaiter.h"
#include <unistd.h>
namespace coro {
read_awaiter::read_awaiter(socket &socket, std::span<char> data,
                           size_t num_read) noexcept
    : socket_{socket}, data_{data}, num_read_{num_read} {}

void read_awaiter::await_resume() const {
  if (exception_ != nullptr) {
    std::rethrow_exception(exception_);
  }
}

void read_awaiter::await_suspend(
    std::experimental::coroutine_handle<> coroutine) {
  coroutine_ = coroutine;
  event_ = event{socket_.get_io_context(), socket_.fd(), event::what::read,
                 &read_awaiter::on_readable, static_cast<void *>(this)};
  event_.activate();
}

void read_awaiter::on_readable(int, short, void *context) noexcept {
  auto &self = *static_cast<read_awaiter *>(context);
  try {
    int ret = ::read(self.socket_.fd(),
                     static_cast<void *>(self.data_.data() + self.num_read_),
                     self.data_.size() - self.num_read_);
    if (ret == -1) {
      throw std::runtime_error{"read failed"};
    }
    if (ret == 0) {
      throw std::runtime_error{"unexpected eof"};
    }
    self.num_read_ += static_cast<size_t>(ret);
    if (self.num_read_ == self.data_.size()) {
      self.coroutine_.resume();
    }
  } catch (...) {
    self.exception_ = std::current_exception();
    self.coroutine_.resume();
  }
}
} // namespace coro