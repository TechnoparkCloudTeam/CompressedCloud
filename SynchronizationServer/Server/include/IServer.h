#include <memory>


class IServer {
public:
    virtual void run() = 0;
    virtual void shutDown() = 0;
};