#include "cc/coro/detached_task_handle.h"
#include "cc/coro/detached_task.h"
#include <experimental/coroutine>
namespace coro {
detached_task_handle::detached_task_handle(
    std::experimental::coroutine_handle<> coroutine) noexcept
    : coroutine_{coroutine} {}

bool detached_task_handle::finish() noexcept {
  if (finished_.exchange(true)) {
    return false;
  }
  coroutine_.destroy();
  return true;
}
} // namespace coro