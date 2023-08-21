#pragma once
#include "cc/ir/indexer/types.h"
#include <map>
namespace ir {
class InvertedIndex {

private:
  std::map<Term, PostingList> index_;
};
} // namespace ir