#include "cc/coro/accept.h"
#include "cc/coro/detached_task.h"
#include "cc/coro/endpoint.h"
#include "cc/coro/io_context.h"
#include "cc/coro/read.h"
#include "cc/coro/socket.h"
#include "cc/coro/state.h"
#include "cc/coro/write.h"

static coro::detached_task process_session(coro::socket socket) {
  std::array<char, 500> buffer;
  while (true) {
    co_await coro::until_readable(socket);
    auto read_result = coro::read(socket, {buffer.data(), buffer.size()});
    if (read_result.eof()) {
      co_return;
    }
    co_await coro::write(socket, {buffer.data(), read_result.num_read()});
  }
}

static coro::detached_task run_server(coro::socket &listener_socket) {
  while (true) {
    auto socket = co_await coro::accept(listener_socket);
    process_session(std::move(socket));
  }
}

int main(int argc, char **argv) {
  coro::io_context context;
  coro::endpoint endpoint{"127.0.0.1", 8080};
  coro::socket socket{context};
  socket.bind(endpoint);
  coro::listen(socket, 10);
  run_server(socket);
  context.run();
  return 0;
}