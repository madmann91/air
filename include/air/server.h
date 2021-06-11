#ifndef AIR_SERVER_H
#define AIR_SERVER_H

#include <sol/scene.h>

namespace air {

class Server {
public:
    Server(uint32_t port);
    ~Server();

    void run();

private:
    sol::Scene scene_;
    uint32_t port_;
};

} // namespace air

#endif
