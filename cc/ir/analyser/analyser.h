#pragma once

#include <string>
namespace ir {
/*
Analyser is an interface defines how does analyser work.
1. Tokenization
2. Post-Processing
3. Build Inverted Index based on those terms.
*/
class Analyser {
public:
  virtual std::string next_token() = 0;
};
} // namespace ir