#pragma once

#include "cc/cetty/channel.h"
#include "cc/cetty/server.h"
#include "glog/logging.h"

namespace cetty {

class ServerConnectionCallback : public cetty::IConnectionCallback {
public:
  ServerConnectionCallback() {}
  ~ServerConnectionCallback() {}
  void onConnection(cetty::Connection *) override {}
  void onMessage(cetty::Connection *conn, common::Buffer *message) override {
    LOG(ERROR) << "message = " << message->readAsString();
    conn->sendMessage("hello client");
  }
  void onWriteComplete(cetty::Connection *) override {}
};

class TCPServer : public Server {
public:
  TCPServer(EventLoop *loop);
  ~TCPServer();
};
} // namespace cetty