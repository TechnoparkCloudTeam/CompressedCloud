#pragma once

#include <vector>

struct ChunkMeta
{
	int chunkId;
};

struct FileChunksMeta
{
	int chunkId;
	int chunkOrder;
};

struct FileMeta
{
	int fileId;
	int userId;
	int version;
	std::string fileName;
	std::string fileExtension;
	std::string filePath;
	int fileSize;
	int chunksCount;
	bool isDownload;
	bool isDeleted;
	bool isCurrent;
	std::string updateDate;
	std::string createDate;

	std::string GetFilePath() const
	{
		return filePath + '/' + fileName + fileExtension;
	}
};

struct FileInfo
{
	int userId;
	FileMeta file;
	std::vector<ChunkMeta> chunkMeta;
	std::vector<FileChunksMeta> fileChunksMeta;
};
