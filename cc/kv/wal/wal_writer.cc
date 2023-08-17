#include "wal_writer.h"
#include "cc/kv/wal/crc32.h"

namespace sleek::oxygen {
int WalWriter::Write(const std::string_view &log) {
  char header[headerSize_];
  /// +---------------+----------+
  /// |checksum(4byte)|len(4byte)|
  /// +---------------+----------+
  auto len = log.size();
  auto checksum =
      static_cast<uint32_t>(crc32c(0xFFFFFFFF, log.data(), log.size()));
  header[0] = checksum & 0xff;
  header[1] = (checksum >> 8) & 0xff;
  header[2] = (checksum >> 16) & 0xff;
  header[3] = (checksum >> 24) & 0xff;
  header[4] = len & 0xff;
  header[5] = (len >> 8) & 0xff;
  header[6] = (len >> 16) & 0xff;
  header[7] = (len >> 24) & 0xff;
  auto s = fw_->append(header, headerSize_);
  assert(s == 0);
  s = fw_->append(log.data(), static_cast<int32_t>(len), true);
  fw_->sync();
}
} // namespace sleek::oxygen
