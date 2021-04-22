#include <string>
#include "IServer.h"

class FileStorageServer : public IServer {
public:
    void run() override;

    void shutDown() override;

    std::string getChunk();

    void sendChunk(std::string json);

private:
    //std::shared_ptr <IClientSession> Synchronizator;
    //std::shared_ptr <IFileStorage> FileStorage;
};