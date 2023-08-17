#include "cc/coro/io_context.h"

#include <cassert>
#include <event2/event.h>
#include <iostream>
#include <stdexcept>

namespace coro {
io_context::io_context() {
  handle_ = static_cast<void *>(event_base_new());
  if (handle_ == nullptr) {
    throw std::runtime_error{"event_base_new failed"};
  }
}

io_context::io_context(io_context &&other) noexcept {
  handle_ = other.handle_;
  other.handle_ = nullptr;
}

io_context::~io_context() noexcept { free(); }

io_context &io_context::operator=(io_context &&other) noexcept {
  assert(&other != this);
  free();
  handle_ = other.handle_;
  other.handle_ = nullptr;
  return *this;
}

void io_context::run() {
  assert(handle_ != nullptr);
  auto ret = event_base_dispatch(static_cast<event_base *>(handle_));
  if (ret == -1) {
    throw std::runtime_error{"event_base_dispatch failed"};
  }
}

void io_context::stop() noexcept {
  assert(handle_ != nullptr);
  auto ret = event_base_loopbreak(static_cast<event_base *>(handle_));
  if (ret != 0) {
    std::cerr << "event_base_loopbreak failed \n";
    std::terminate();
  }
}

void io_context::free() noexcept {
  if (handle_ != nullptr) {
    event_base_free(static_cast<event_base *>(handle_));
  }
}
} // namespace coro