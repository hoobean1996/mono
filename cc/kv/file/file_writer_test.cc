#include "cc/kv/file/file_reader.h"
#include "cc/kv/file/file_writer.h"
#include <gtest/gtest.h>

TEST(FILEIO, BAISC) {
  sleek::oxygen::FileWriter fw("./f.txt", false);
  std::string msg("hello world");
  fw.append(msg.c_str(), msg.size(), true);

  sleek::oxygen::FileReader fr("./f.txt");
  char buf[1024];
  fr.read(buf, msg.size());
  std::string msg2(buf, msg.size());
  EXPECT_EQ(msg, msg2);
}