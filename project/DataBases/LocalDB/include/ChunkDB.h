#include <vector>
#include<memory>
#include "LocalDB.h"

struct Chunks {
        int userId;
        int chunkId;
        std::vector<char> data;
};

class ChunkDB {
public:
        std::vector<Chunks> getChunks(const int &fileId);
        void addChunks(const std::vector<Chunks> &chunks, const int &fileId);
private:
        Chunks chunk;
        int fileId;
        std::shared_ptr<LocalDB> localDB;
};
