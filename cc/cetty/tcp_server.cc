#include "cc/cetty/tcp_server.h"
#include "cc/cetty/channel.h"
#include "cc/cetty/connection.h"
#include "cc/cetty/server.h"
#include <ostream>

namespace cetty {
TCPServer::TCPServer(EventLoop *loop)
    : Server(loop, new ServerConnectionCallback()) {}

TCPServer::~TCPServer() {}
} // namespace cetty