#include "cc/coro/endpoint.h"
#include <_types/_uint16_t.h>
#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <stdexcept>
#include <sys/socket.h>

namespace coro {
endpoint::endpoint(const char *s, uint16_t port) {
  auto &ipv4_addr = reinterpret_cast<sockaddr_in &>(data_);
  auto ret = inet_pton(AF_INET, s, static_cast<void *>(&ipv4_addr.sin_addr));
  if (ret == 1) {
    ipv4_addr.sin_family = AF_INET;
    ipv4_addr.sin_port = htons(port);
    return;
  }

  auto &ipv6_addr = reinterpret_cast<sockaddr_in6 &>(data_);
  ret = inet_pton(AF_INET6, s, static_cast<void *>(&ipv6_addr.sin6_addr));
  if (ret == 1) {
    ipv6_addr.sin6_family = AF_INET6;
    ipv6_addr.sin6_port = htons(port);
    return;
  }
  throw std::runtime_error{"failed to construct IpAddress"};
}

size_t endpoint::length() const noexcept {
  switch (this->family()) {
  case AF_INET:
    return sizeof(sockaddr_in);
  case AF_INET6:
    return sizeof(sockaddr_in6);
  }
  std::cerr << "unknown family \n";
  std::terminate();
}

bool operator==(const endpoint &lhs, const endpoint &rhs) noexcept {
  auto ret =
      std::memcmp(static_cast<const void *>(&lhs.data_),
                  static_cast<const void *>(&rhs.data_), sizeof(lhs.data_));
  return ret == 0;
}
} // namespace coro