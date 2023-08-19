#pragma once

#include <memory>

#include "cc/kv/offset_info.h"
namespace sleek::oxygen {
class DataBlockBuilder;
class FilterBlockBuilder;
class IndexBlockBuilder;
class FileWriter;
class FooterBuilder;

/// SSTable layout
/// DataBlock_1
/// DataBlock_2
/// ...
/// DataBlock_n
/// MetaBlock
/// IndexBlock_1
/// IndexBlock_2
/// ...
/// IndexBlock_n
/// Footer

class SSTableBuilder final {
public:
  SSTableBuilder() = default;
  ~SSTableBuilder() = default;
  explicit SSTableBuilder(int32_t keysNum, std::shared_ptr<FileWriter> fw,
                          double falsePositive = 0.01);
  int add(const std::string &key, const std::string &value);
  int finish_sst();

private:
  std::shared_ptr<DataBlockBuilder> dataBlockBuilder_ = nullptr;
  std::shared_ptr<IndexBlockBuilder> indexBlockBuilder_ = nullptr;
  std::shared_ptr<FilterBlockBuilder> filterBlockBuilder_ = nullptr;
  std::shared_ptr<FileWriter> fileWriter_ = nullptr;
  std::shared_ptr<FooterBuilder> footerBuilder_ = nullptr;

  OffsetInfo FilterBlockOffset_{0, 0};
  OffsetInfo IndexBlockOffset_{0, 0};

  int32_t keysNum_ = 0;
  double falsePositive_ = 0;
};
} // namespace sleek::oxygen