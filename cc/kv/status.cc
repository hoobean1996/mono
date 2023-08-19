#include "cc/kv/status.h"

namespace sleek::oxygen {
bool operator==(const Status &lhs, const Status &rhs) {
  return lhs.code == rhs.code;
}

bool operator!=(const Status &lhs, const Status &rhs) {
  return lhs.code != rhs.code;
}
} // namespace sleek::oxygen