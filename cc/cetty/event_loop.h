#pragma once

#include "cc/cetty/channel.h"
#include "cc/cetty/poller.h"
namespace cetty {
class EventLoop {
public:
  EventLoop();
  ~EventLoop();

  void loop();
  void update(Channel *channel);

private:
  bool running_;
  Poller *poller_;
};
} // namespace cetty