#include "../include/Indexer.h"
#include <iostream>
Indexer::Indexer (std::shared_ptr<UserDB> localDB) {

}

Indexer::Indexer() {
    
}
void Indexer::createFile(const std::filesystem::path& path, size_t chunksCnt) {
    return;
}
void Indexer::modifyFile(const std::filesystem::path& path, size_t chunksCnt) {
    return;
}
void Indexer::renameFile(const std::filesystem::path& oldPath,
        const std::filesystem::path& newPath) {
        return;
        }
void Indexer::deleteFile(const std::filesystem::path& path) {
    return;
}
void Indexer::getFileInfo(const std::filesystem::path& path) {
    return;
}

void Indexer::AddUser(UserDB& DB) {
    

  
}