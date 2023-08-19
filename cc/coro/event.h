#pragma once
#include "cc/coro/io_context.h"
#include <chrono>
namespace coro {
class event {
public:
  struct what {
    static const short write;
    static const short read;
  };

  using handle_type = void *;
  using callback_type = void (*)(int fd, short what, void *context) noexcept;
  event() noexcept = default;
  event(io_context &io_context, int fd, short what, callback_type callback,
        void *context);
  event(const event &) = delete;
  event(event &&other) noexcept;
  ~event() noexcept;
  event &operator=(const event &) = delete;
  event &operator=(event &&other) noexcept;
  void activate();
  void activate(std::chrono::microseconds timeout);

  template <class Rep, class Period>
  void activate(std::chrono::duration<Rep, Period> timeout) {
    return activate(
        std::chrono::duration_cast<std::chrono::milliseconds>(timeout));
  }

  void deactivate();

private:
  handle_type handle_{nullptr};
  void free() noexcept;
};
} // namespace coro