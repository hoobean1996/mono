#pragma once

#include <string>
namespace sleek::oxygen {
class Comparator {
 public:
  Comparator() = default;
  virtual ~Comparator() = 0;
  virtual std::string name() = 0;
  virtual int32_t compare(const std::string& lhs, const std::string& rhs) = 0;
};
}  // namespace sleek::oxygen