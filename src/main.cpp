#include <cstdint>
#include <iostream>
#include <string_view>
#include <optional>

#include "air/server.h"

struct Options {
    uint32_t port = 8800;
};

static void usage() {
    std::cout
        << "Usage: sol-air [options]\n"
        << "Available options:\n"
        << " -h   --help    Shows this message\n"
        << " -p   --port    Sets the server port\n";
}

static bool has_arg(int i, int argc, char** argv) {
    if (i == argc - 1) {
        std::cerr << "Missing argument for '" << argv[i] << "'" << std::endl;
        return false;
    }
    return true;
}

static inline std::optional<Options> parse_options(int argc, char** argv) {
    Options options;
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
    using namespace air;

    auto options = parse_options(argc, argv);
    if (!options)
        return 1;

    Server server(options->port);
    server.run();
    return 0;
}
