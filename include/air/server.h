#ifndef AIR_SERVER_H
#define AIR_SERVER_H

#include <memory>
#include <cstdint>

namespace air {

// FIXME: Workaround gcc/clang bug (this should be part of Server).
// See https://gcc.gnu.org/bugzilla/show_bug.cgi?id=88165
// and https://bugs.llvm.org/show_bug.cgi?id=36684
namespace detail {

struct Options {
    uint32_t port = 8800;
    bool verbose = false;
};

} // namespace detail

struct ServerImpl;

class Server {
public:
    using Options = detail::Options;

    Server(const Options& options = {});
    ~Server();

    bool run();

private:
    Options options_;
    std::unique_ptr<ServerImpl> impl_;
};

} // namespace air

#endif
