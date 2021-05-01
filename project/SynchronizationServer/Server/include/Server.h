#include "IServer.h"
#include "Synchronizator.h"

class Server : public IServer {
public:
    void run() override;
    void shutDown() override;
private:
    std::shared_ptr <ISyncronizator> Synchronizator;
};