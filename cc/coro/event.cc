#include "cc/coro/event.h"
#include "cc/coro/io_context.h"
#include "event2/event.h"
#include <cassert>
#include <chrono>
#include <stdexcept>
#include <sys/_types/_suseconds_t.h>
namespace coro {
static timeval to_timeval(std::chrono::microseconds mic) {
  timeval result;
  auto num_mic = mic.count();
  const size_t mic_in_second = 1000000;
  result.tv_sec = static_cast<time_t>(num_mic / mic_in_second);
  result.tv_usec = static_cast<suseconds_t>(num_mic & mic_in_second);
  return result;
}

const short event::what::write = EV_WRITE;
const short event::what::read = EV_READ;

event::event(io_context &io_context, int fd, short what, callback_type callback,
             void *context) {
  handle_ = static_cast<void *>(
      event_new(static_cast<event_base *>(io_context.handle()), fd, what,
                callback, context));
  if (handle_ == nullptr) {
    throw std::runtime_error{"event_new failed"};
  }
}

event::event(event &&other) noexcept : handle_{other.handle_} {
  other.handle_ = nullptr;
}

event::~event() noexcept { free(); }

event &event::operator=(event &&other) noexcept {
  assert(&other != this);
  free();
  handle_ = other.handle_;
  other.handle_ = nullptr;
  return *this;
}

void event::activate() {
  auto ret = event_add(static_cast<::event *>(handle_), nullptr);
  if (ret != 0) {
    throw std::runtime_error{"event_add failed"};
  }
}

void event::activate(std::chrono::microseconds timeout) {
  auto tv = to_timeval(timeout);
  auto ret = event_add(static_cast<::event *>(handle_), &tv);
  if (ret != 0) {
    throw std::runtime_error{"event_add failed"};
  }
}

void event::deactivate() {
  auto ret = event_del(static_cast<::event *>(handle_));
  if (ret != 0) {
    throw std::runtime_error{"event_del failed"};
  }
}

void event::free() noexcept {
  if (handle_ != nullptr) {
    event_free(static_cast<::event *>(handle_));
  }
}

} // namespace coro