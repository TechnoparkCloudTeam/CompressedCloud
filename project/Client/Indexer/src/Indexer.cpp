#include "../include/Indexer.h"

Indexer::Indexer (std::shared_ptr<UserDB> localDB) {

}
FileMeta Indexer::createFile(const std::filesystem::path& path, size_t chunksCnt) {
    return FileMeta();
}
FileMeta Indexer::modifyFile(const std::filesystem::path& path, size_t chunksCnt) {
    return FileMeta();
}
FileMeta Indexer::renameFile(const std::filesystem::path& oldPath,
        const std::filesystem::path& newPath) {
        return FileMeta();
        }
FileMeta Indexer::deleteFile(const std::filesystem::path& path) {
    return FileMeta();
}
FileMeta Indexer::getFileInfo(const std::filesystem::path& path) {
    return FileMeta();
}
