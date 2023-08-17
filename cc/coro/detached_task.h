#pragma once

#include <experimental/coroutine>
#include <memory>
namespace coro {
class detached_task_promise;
class detached_task_handle;

class detached_task {
public:
  using promise_type = detached_task_promise;
  explicit detached_task(std::shared_ptr<detached_task_handle> handle);
  bool cancel() noexcept;

private:
  std::shared_ptr<detached_task_handle> handle_;
};

class detached_task_promise {
public:
  class final_awaiter {
  public:
    explicit final_awaiter(
        std::shared_ptr<detached_task_handle> handle) noexcept;
    void await_resume() const noexcept {}
    bool await_ready() const noexcept { return false; }
    void
    await_suspend(std::experimental::coroutine_handle<> coroutine) noexcept;

  private:
    std::shared_ptr<detached_task_handle> handle_;
  };

  detached_task_promise();
  detached_task get_return_object();
  std::experimental::suspend_never initial_suspend() noexcept { return {}; }

private:
  std::shared_ptr<detached_task_handle> handle_;
};

} // namespace coro