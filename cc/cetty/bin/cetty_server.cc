#include "cc/cetty//connection.h"
#include "cc/cetty/core.h"
#include "cc/cetty/event_loop.h"
#include "cc/cetty/server.h"
#include "cc/cetty/tcp_server.h"
#include "gflags.h"
#include "glog/logging.h"
#include <csignal>

void signalHandler(int signum) {
  LOG(ERROR) << "signalHandler: signal=" << signum;
}

DEFINE_int32(port, 8001, "TCP Server port");

int main(int argc, char *argv[]) {
  yummy::initYummy(argc, argv);
  signal(SIGINT, signalHandler);
  cetty::EventLoop loop{};
  cetty::TCPServer server{&loop};
  server.start(FLAGS_port);
  loop.loop();
  return 0;
}