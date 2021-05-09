#include <vector>
#include <memory>
#include <string>

struct FileMeta {
        int id;
        std::string fileName;
        int fileSize;
        int version;
        int quantityChunks;
};
