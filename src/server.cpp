#include <exception>

#include <spdlog/spdlog.h>
#include <sol/scene.h>
#include <asio.hpp>

#include "air/server.h"

using asio::ip::tcp;

namespace air {

struct ServerImpl {
    ServerImpl(const Server::Options& options)
        : options(options), acceptor(context, tcp::endpoint(tcp::v4(), options.port))
    {}

    ~ServerImpl() {
        spdlog::info("Shutting down server");
    }

    void run() {
        spdlog::info("Starting server on port {}", options.port);
        // TODO
    }

    const Server::Options& options;
    sol::Scene scene;
    asio::io_context context;
    tcp::acceptor acceptor;
};

Server::Server(const Options& options)
    : options_(options)
{}

Server::~Server() = default;

bool Server::run() {
    try {
        impl_ = std::make_unique<ServerImpl>(options_);
        impl_->run();
    } catch (std::exception& e) {
        spdlog::error("Exception caught: \"{}\"", e.what());
        return false;
    }
    return true;
}

} // namespace air
