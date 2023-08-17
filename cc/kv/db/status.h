#pragma once

#include <sys/_types/_int32_t.h>
namespace sleek::oxygen {
struct Status {
  int32_t code;
  const char *error_message;
};

bool operator==(const Status &lhs, const Status &rhs);
bool operator!=(const Status &lhs, const Status &rhs);

static constexpr Status OK = {1, "Success"};
} // namespace sleek::oxygen