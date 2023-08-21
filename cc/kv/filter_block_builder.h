#pragma once

#include <memory>
namespace kv {
class FilterPolicy;

class FilterBlockBuilder final {
private:
  std::shared_ptr<FilterPolicy> filterPolicy_ = nullptr;
};
} // namespace kv