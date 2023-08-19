#include "cc/coro/write.h"
#include "cc/coro/write_awaiter.h"
#include <unistd.h>
namespace coro {
write_result::write_result(socket &socket, std::span<const char> data,
                           size_t num_written) noexcept
    : socket_{socket}, data_{data}, num_written_{num_written} {}

write_awaiter write_result::operator co_await() const noexcept {
  return {socket_, data_, num_written_};
}

write_result write(socket &socket, std::span<const char> data) {
  int ret =
      ::write(socket.fd(), static_cast<const void *>(data.data()), data.size());
  if (ret == -1) {
    if (errno != EAGAIN && errno != EWOULDBLOCK) {
      throw std::runtime_error{"write failed"};
    }
    ret = 0;
  }
  return write_result{socket, data, static_cast<size_t>(ret)};
}
} // namespace coro