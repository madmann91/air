#include <spdlog/spdlog.h>

#include "air/server.h"

namespace air {

Server::Server(uint32_t port)
    : port_(port)
{
    // TODO
}

Server::~Server() {
    spdlog::info("Shutting down server", port_);
}

void Server::run() {
    spdlog::info("Starting server on port {}", port_);
    // TODO
}

} // namespace air
