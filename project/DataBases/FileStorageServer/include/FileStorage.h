#include "IFileStorage.h"

class FileStorage : public IFileStorage {
public:
        void connect() override;
        void disconnect() override;
        void addChunk(const std::vector<Chunk> &chunks) override;
        std::vector<Chunk> getChunk(const std::vector<Chunk> &chunks) override;
private:
  //      mongocxx::database _database;
  //      mongocxx::client _client;
};
