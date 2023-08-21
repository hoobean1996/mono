#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>

#include "cc/kv/file_writer.h"

int main(int argc, char **argv) {
  google::InitGoogleLogging(argv[0]);
  FLAGS_logtostderr = true;
  LOG(INFO) << "hello world!";
  kv::FileWriter fw("./demo.txt");
  std::string m1 = "hello world";
  fw.append(m1.c_str(), m1.size());
  return 0;
}