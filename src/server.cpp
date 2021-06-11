#include <spdlog/spdlog.h>

#include "air/server.h"

namespace air {

Server::Server(const Options& options)
    : options_(options)
{
    // TODO
}

Server::~Server() {
    spdlog::info("Shutting down server");
}

void Server::run() {
    spdlog::info("Starting server on port {}", options_.port);
    // TODO
}

} // namespace air
