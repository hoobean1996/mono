#include "cc/coro/event.h"
#include "cc/coro/socket.h"
#include <experimental/coroutine>
namespace coro {
class [[nodiscard]] socket_state_awaiter {
public:
  socket_state_awaiter(socket &socket, short what);
  short await_resume() const noexcept;
  bool await_ready() const noexcept { return false; }
  void await_suspend(std::experimental::coroutine_handle<> coroutine);

private:
  socket &socket_;
  event event_;
  std::experimental::coroutine_handle<> coroutine_{nullptr};
  short what_;
  short state_what_;

  static void on_state_change(int fd, short what, void *context) noexcept;
};
} // namespace coro