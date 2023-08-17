#include "cc/coro/detached_task.h"
#include "cc/coro/detached_task_handle.h"

namespace coro {
detached_task::detached_task(std::shared_ptr<detached_task_handle> handle)
    : handle_{std::move(handle)} {}

bool detached_task::cancel() noexcept { return handle_->finish(); }
} // namespace coro