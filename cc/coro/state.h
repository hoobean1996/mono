#pragma once

#include "cc/coro/socket.h"
#include "cc/coro/socket_state_awaiter.h"
namespace coro {
socket_state_awaiter until_readable(socket &socket);
socket_state_awaiter untile_writeable(socket &socket);
} // namespace coro