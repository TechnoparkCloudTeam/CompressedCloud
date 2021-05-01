#include <vector>

struct Chunk {
        int userId;
        int chunkId;
        std::vector<char> data;
};

class IFileStorage {
public:
        virtual void connect() = 0;
        virtual void disconnect() = 0;
        virtual void addChunk(const std::vector<Chunk> &chunks) = 0;
        virtual std::vector<Chunk> getChunk(const std::vector<Chunk> &chunks) = 0;
};
