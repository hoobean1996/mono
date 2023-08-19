#include "cc/coro/write_awaiter.h"
#include <unistd.h>
namespace coro {
write_awaiter::write_awaiter(socket &socket, std::span<const char> data,
                             size_t num_written) noexcept
    : socket_{socket}, data_{data}, num_written_{num_written} {}

void write_awaiter::await_resume() const {
  if (exception_ != nullptr) {
    std::rethrow_exception(exception_);
  }
}

void write_awaiter::await_suspend(
    std::experimental::coroutine_handle<> coroutine) {
  coroutine_ = coroutine;
  event_ = event{socket_.get_io_context(), socket_.fd(), event::what::write,
                 &write_awaiter::on_writable, static_cast<void *>(this)};
  event_.activate();
}

void write_awaiter::on_writable(int /*file descriptor*/, short /*what*/,
                                void *context) noexcept {
  auto &self = *static_cast<write_awaiter *>(context);
  try {
    int ret = ::write(
        self.socket_.fd(),
        static_cast<const void *>(self.data_.data() + self.num_written_),
        self.data_.size() - self.num_written_);
    if (ret == -1) {
      throw std::runtime_error{"write failed"};
    }
    self.num_written_ += static_cast<size_t>(ret);
    if (self.num_written_ == self.data_.size()) {
      self.coroutine_.resume();
    }
  } catch (...) {
    self.exception_ = std::current_exception();
    self.coroutine_.resume();
  }
}
} // namespace coro