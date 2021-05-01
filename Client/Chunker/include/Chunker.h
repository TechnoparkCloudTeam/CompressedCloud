#pragma once
#include <array>
#include <string>
#include <iostream>
#include <vector>
#include <filesystem>
#define ChunkSize 256

struct FileChunk {
	std::array<char, ChunkSize> data;
	std::string ChunkHash;
	std::string FileHash;
};

bool operator== (const FileChunk& lhs, const FileChunk& rhs) {
	return lhs.data == rhs.data;
}

class IChunker {
public:
	virtual std::vector<FileChunk> chunkFile(std::filesystem::path Path) = 0;
	virtual void updateFileChunks(std::filesystem::path Path) = 0;
	virtual void buildFile(std::vector<FileChunk> fileChunks) = 0;

};

class Chunker : public IChunker{
public:
	std::vector<FileChunk> chunkFile(std::filesystem::path path) override;
	void updateFileChunks(std::filesystem::path path) override;
	void buildFile(std::vector<FileChunk> fileChunks) override;
private:
	std::string GetFileHash();
	std::string getChunkHash();
	FileChunk createChunk();
	std::filesystem::path path;
	std::vector< FileChunk > FileChunks;
};