#include "cc/coro/read.h"
#include <span>
#include <unistd.h>
namespace coro {
read_result::read_result(socket &socket, std::span<char> data, size_t num_read,
                         bool eof) noexcept
    : socket_{socket}, data_{data}, num_read_{num_read}, eof_{eof} {}

read_awaiter read_result::operator co_await() const {
  if (eof_) {
    throw std::runtime_error{"unexpected eof"};
  }
  return {socket_, data_, num_read_};
}

read_result read(socket &socket, std::span<char> data) {
  int ret = ::read(socket.fd(), static_cast<void *>(data.data()), data.size());
  bool eof = false;
  if (ret == -1) {
    if (errno != EAGAIN && errno != EWOULDBLOCK) {
      throw std::runtime_error{"read failed"};
    }
    ret = 0;
  } else if (ret == 0) {
    eof = true;
  }
  return read_result{socket, data, static_cast<size_t>(ret), eof};
}
} // namespace coro