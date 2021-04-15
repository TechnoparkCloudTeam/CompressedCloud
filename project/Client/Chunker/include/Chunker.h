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

class IChunker {
public:
	
	virtual void GetFile(std::fstream& file) = 0;

	virtual void SendChunks() = 0;

};

class Chunker : public IChunker{
public:
	bool CompareChunks(const FileChunk& lhs, const FileChunk& rhs);

	void GetFile(std::fstream& file) override;

	void ParseFile();

	void GetNewChunk();

	void SendChunks();
private:
	std::string GetChecksum();
	std::string GetOldChecksum();
	void ChangeNewChunk();
	std::vector< FileChunk > FileChunks;
	//std::filesystem::path Path;
};