#include "cc/coro/task.h"
#include <gtest/gtest.h>
#include <iostream>

static coro::task<int> f42() { co_return 42; }

static coro::task<void> process() {
  auto x = co_await f42();
  std::cout << "x = " << x << std::endl;
}

TEST(Coro, Task) {
  EXPECT_EQ(2, 1 + 1);
  process();
}