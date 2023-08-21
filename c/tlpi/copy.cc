#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <glog/logging.h>
#include <sys/_types/_ssize_t.h>
#include <sys/stat.h>
#include <unistd.h>

const int kBufSize = 1024;

int main(int argc, char **argv) {
  int infd, outfd, open_flags;
  mode_t file_permissions;
  ssize_t num_read;
  char buf[kBufSize];
  if (argc != 3 || strcmp(argv[1], "--help") == 0) {
    LOG(ERROR) << "copy [arg1] [arg2], two arguments are required";
    exit(1);
  }
  infd = open(argv[1], O_RDONLY);
  if (infd == -1) {
    LOG(ERROR) << "can't open the original file to copy";
    exit(1);
  }
  open_flags = O_CREAT | O_WRONLY | O_TRUNC;
  file_permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
  outfd = open(argv[2], open_flags, file_permissions);
  while ((num_read = ::read(infd, buf, kBufSize)) > 0) {
    if (write(outfd, buf, num_read) != num_read) {
      exit(1);
    }
  }
  if (num_read == -1) {
    LOG(ERROR) << "can't read data from the orignal file";
    exit(1);
  }
  if (close(infd) == -1) {
    LOG(ERROR) << "close original file fialed";
    exit(1);
  }
  if (close(outfd) == -1) {
    LOG(ERROR) << "close copied file failed";
    exit(1);
  }
  return 0;
}