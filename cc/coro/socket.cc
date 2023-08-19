#include "cc/coro/socket.h"
#include "cc/coro/io_context.h"
#include <cassert>
#include <cstring>
#include <stdexcept>
#include <sys/errno.h>
#include <sys/fcntl.h>
#include <sys/socket.h>
#include <unistd.h>
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

socket::socket(io_context &io_context) noexcept : io_context_{io_context} {}
socket::socket(io_context &io_context, const endpoint &endpoint)
    : io_context_{io_context} {
  this->connect(endpoint);
}
socket::socket(io_context &io_context, int fd) noexcept
    : io_context_{io_context}, fd_{fd} {}
socket::socket(socket &&other) noexcept
    : io_context_{other.io_context_}, fd_{other.fd_} {
  other.fd_ = -1;
}

socket::~socket() noexcept { free(); }
socket &socket::operator=(socket &&other) noexcept {
  assert(&other != this);
  free();
  fd_ = other.fd_;
  other.fd_ = -1;
  return *this;
}

void socket::connect(const endpoint &endpoint) {
  this->open(endpoint.family());
  auto ret = ::connect(fd_, &static_cast<const sockaddr &>(endpoint),
                       endpoint.length());
  if (ret == -1 && errno != EINPROGRESS) {
    throw std::runtime_error{"connect failed:"};
  }
}

void socket::bind(const endpoint &endpoint) {
  this->open(endpoint.family());
  auto ret =
      ::bind(fd_, &static_cast<const sockaddr &>(endpoint), endpoint.length());
  if (ret == -1) {
    throw std::runtime_error{"bind failed"};
  }
}

void socket::open(int family) {
  fd_ = ::socket(family, SOCK_STREAM, 0);
  if (fd_ == -1) {
    throw std::runtime_error{"socket failed"};
  }
  set_nonblocking(fd_);
  set_reuse_address(fd_);
}

void socket::free() noexcept {
  if (fd_ != -1) {
    ::close(fd_);
  }
}

void listen(socket &socket, int backlog) {
  auto ret = ::listen(socket.fd(), backlog);
  if (ret == -1) {
    throw std::runtime_error{"listen failed"};
  }
}

} // namespace coro