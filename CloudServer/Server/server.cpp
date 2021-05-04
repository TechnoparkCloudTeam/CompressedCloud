#include <iostream>
#include "Server.h"

enum class msgTypes : uint32_t
{
    ServerAccept,
    ServerMessage,

};
namespace cloudserver
{
    class TestServer : public cloudserver::CloudServer<msgTypes>
    {
    public:
        TestServer(int port) : cloudserver::CloudServer<msgTypes>(port)
        {
        }

    private:
        bool onClientConnect(std::shared_ptr<connection::Session<msgTypes>> client)
        {
            return true;
        }
    };
}
int main()
{
    cloudserver::TestServer server(6666);
    server.start();

    while (1)
    {
        server.update();
    }
}