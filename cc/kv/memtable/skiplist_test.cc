#include "skiplist.h"
#include <gtest/gtest.h>

TEST(FILEIO, BAISC) {
  sleek::oxygen::SkipList<std::string, std::string> skiplist{};
  skiplist.insert("key", "value");
  auto value = skiplist.search("key");
  EXPECT_EQ("value", value);
}