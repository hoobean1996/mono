#pragma once

#include <sys/socket.h>
namespace coro {
class endpoint {
public:
  endpoint() noexcept = default;
  endpoint(const char *s, uint16_t port);
  sa_family_t family() const noexcept { return data_.ss_family; }
  size_t length() const noexcept;
  operator const sockaddr &() const noexcept {
    return reinterpret_cast<const sockaddr &>(data_);
  }

private:
  ::sockaddr_storage data_{};
  friend bool operator==(const endpoint &lhs, const endpoint &rhs) noexcept;
};

bool operator==(const endpoint &lhs, const endpoint &rhs) noexcept;
inline bool operator!=(const endpoint &lhs, const endpoint &rhs) noexcept {
  return !(lhs == rhs);
}

} // namespace coro