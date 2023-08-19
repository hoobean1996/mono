#pragma once

#include <memory>
namespace sleek::oxygen {
class FilterPolicy;

class FilterBlockBuilder final {
 private:
  std::shared_ptr<FilterPolicy> filterPolicy_ = nullptr;
};
}  // namespace sleek::oxygen