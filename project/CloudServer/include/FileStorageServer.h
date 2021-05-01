#include <string>
#include "IServer.h"
#include "../../DataBases/FileStorageServer/include/FileStorage.h"

class FileStorageServer : public IServer {
public:
    void run() override;

    void shutDown() override;

    std::string getChunk();

    void sendChunk(std::string json);

private:
    std::shared_ptr <IFileStorage> FileStorage;
};