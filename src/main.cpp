#include <cstdint>
#include <iostream>
#include <string_view>
#include <optional>

#include "air/server.h"

using namespace air;

static void usage() {
    std::cout
        << "Usage: air [options]\n"
        << "Available options:\n"
        << " -h   --help     Shows this message\n"
        << " -v   --verbose  Print every message on the console\n"
        << " -p   --port     Sets the server port\n";
}

static bool has_arg(int i, int argc, char** argv) {
    if (i == argc - 1) {
        std::cerr << "Missing argument for '" << argv[i] << "'" << std::endl;
        return false;
    }
    return true;
}

static inline std::optional<Server::Options> parse_options(int argc, char** argv) {
    Server::Options options;
    for (int i = 1; i < argc; ++i) {
        if (argv[i][0] == '-') {
            using namespace std::literals::string_view_literals;
            if (argv[i] == "-h"sv || argv[i] == "--help"sv) {
                usage();
                return std::nullopt;
            } else if (argv[i] == "-p"sv || argv[i] == "--port"sv) {
                if (!has_arg(i, argc, argv))
                    return std::nullopt;
                options.port = std::strtoul(argv[++i], NULL, 10);
            } else if (argv[i] == "-v"sv || argv[i] == "--verbose"sv) {
                options.verbose = true;
            } else {
                std::cerr << "Unknown option '" << argv[i] << "'" << std::endl;
                return std::nullopt;
            }
        } else {
            // TODO: Load config...
        }
    }
    return std::make_optional(options);
}

int main(int argc, char** argv) {
    auto options = parse_options(argc, argv);
    if (!options)
        return 1;

    Server server(*options);
    return server.run() ? 0 : 1;
}
