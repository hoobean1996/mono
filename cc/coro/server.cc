#include "cc/coro/endpoint.h"
#include "cc/coro/io_context.h"
int main(int argc, char **argv) {
  coro::io_context context;
  coro::endpoint endpoint{"127.0.0.1", 8080};
  return 0;
}