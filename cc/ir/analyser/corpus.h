#pragma once

#include <string>
namespace ir {
// Corpus represents a lot of documents.
class Corpus {
public:
  Corpus() = default;
  Corpus(std::vector<std::string> document);

private:
  std::vector<std::string> documents_;
};
} // namespace ir