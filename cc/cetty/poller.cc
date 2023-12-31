#include "cc/cetty/poller.h"
#include "cc/cetty/channel.h"
#include "glog/logging.h"
#include <sys/epoll.h>
#include <unistd.h>

namespace cetty {
Poller::Poller() {
  epollFd_ = ::epoll_create(1);
  if (epollFd_ <= 0) {
    LOG(FATAL) << "epoll_create failed";
  }
}

Poller::~Poller() { close(epollFd_); }

void Poller::poll(std::vector<Channel *> *channels) {
  int fds = ::epoll_wait(epollFd_, events_, maxEventsNum_, -1);
  if (fds == -1) {
    LOG(FATAL) << "epoll_wait failed";
    return;
  }
  for (int i = 0; i < fds; i++) {
    Channel *channel = static_cast<Channel *>(events_[i].data.ptr);
    channel->setReadyEvents(events_[i].events);
    channels->push_back(channel);
  }
}

void Poller::update(Channel *channel) {
  struct epoll_event ev;
  ev.data.ptr = channel;
  ev.events = channel->getEvents();
  int channelFd = channel->getFd();
  int flag = channel->getFlag();
  if (flag == kNew) {
    ::epoll_ctl(epollFd_, EPOLL_CTL_ADD, channelFd, &ev);
    channel->setFlag(kAdded);
  } else if (flag == kAdded) {
    ::epoll_ctl(epollFd_, EPOLL_CTL_MOD, channelFd, &ev);
  } else if (flag == kDeleted) {
    ::epoll_ctl(epollFd_, EPOLL_CTL_DEL, channelFd, &ev);
  }
}

} // namespace cetty