#include <stdexcept>
#include <sys/fcntl.h>
#include <sys/socket.h>
namespace coro {
static void set_reuse_address(int fd) {
  int opt = 1;
  int ret = ::setsockopt(fd, SOL_SOCKET, SO_REUSEADDR,
                         static_cast<void *>(&opt), sizeof(int));
  if (ret == -1) {
    throw std::runtime_error{"failed to set the socket as reuseable"};
  }
}

static void set_nonblocking(int fd) {
  int ret = ::fcntl(fd, F_SETFL, ::fcntl(fd, F_GETFL, 0) | O_NONBLOCK);
  if (ret == -1) {
    throw std::runtime_error{"failed to set the scoket as non-blocking"};
  }
}
} // namespace coro