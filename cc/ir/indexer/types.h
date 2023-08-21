#pragma once

#include <string>
#include <vector>
namespace ir {
using Term = std::string;

class Position {
public:
  Position() = default;
  Position(std::string filename, int row, int column)
      : filename_{filename}, row_{row}, column_{column} {}
  ~Position() = default;

private:
  std::string filename_;
  int row_;
  int column_;
};

using PostingList = std::vector<Position>;
} // namespace ir