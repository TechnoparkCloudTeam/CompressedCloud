#include "../include/Chunker.h"


std::vector<FileChunk> Chunker::chunkFile(std::filesystem::path Path) {
    return std::vector<FileChunk>();
}
void Chunker::updateFileChunks(std::filesystem::path Path) {
    return;
}
void Chunker::buildFile(std::vector<FileChunk> fileChunks) {
    return;
}

std::string Chunker::GetFileHash() {
    return "";
}
std::string Chunker::getChunkHash() {
    return "";
}
FileChunk Chunker::createChunk() {
    return FileChunk();
}
