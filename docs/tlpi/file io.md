# File IO

All system calls for performing I/O refer to open files using a `file descriptor`,
a `nonnegative integer`.

`file descriptor` are used to refer to all types of open files, including

- `pipe`
- `FIFO`
- `socket`
- `terminal`
- `device`
- `regular file`

Each process has its own set of `file descriptor`.

## Standard File Descriptors

By convention, most program expect to be able to use three stand file standards.
These three descriptors are opened on the program's behalf of the shell, before the program is started.

The program inherits copies of the shell's file descriptors.

In an interactive shell, these three file descriptors normally refer to the `terminal` under which the shell is running.

`<unistd.h>`

- 0: stdint, STDIN_FILENO
- 1: stdout, STDOUT_FILENO
- 2: stderr, STDERR_FILENO

## syscalls

- fd = open(pathname, flags, mode)
  the `flags` argument also specifies whether the file to be opened for reading, writing
  the `mode` argument also specifies the permissions to be placed on the file it is created by this call
- numread = read(fd, buffer, count)
- numwritten = write(fd, buffer, count)
- status = close(fd)
