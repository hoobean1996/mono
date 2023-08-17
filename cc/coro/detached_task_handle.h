#pragma once

#include "cc/coro/detached_task.h"
#include <atomic>
#include <experimental/coroutine>

namespace coro {
class detached_task_handle {
public:
  explicit detached_task_handle(
      std::experimental::coroutine_handle<> coroutine) noexcept;
  bool finish() noexcept;

private:
  std::atomic<bool> finished_{false};
  std::experimental::coroutine_handle<void> coroutine_;
};
} // namespace coro