#pragma once

#include "cc/coro/endpoint.h"
#include "cc/coro/io_context.h"
namespace coro {
class socket {
public:
  explicit socket(io_context &io_content) noexcept;
  socket(io_context &io_context, const endpoint &endpoint);
  socket(io_context &io_context, int fs) noexcept;
  socket(const socket &) = delete;
  socket(socket &&other) noexcept;

  ~socket() noexcept;
  socket &operator=(const socket &) = delete;
  socket &operator=(socket &&other) noexcept;

  io_context &get_io_context() noexcept { return io_context_; }
  int fd() const noexcept { return fd_; }
  void connect(const endpoint &endpoint);
  void bind(const endpoint &endpoint);

private:
  io_context &io_context_;
  void open(int family);
  void free() noexcept;
  int fd_{-1};
};

void listen(socket &socket, int backlog);
} // namespace coro