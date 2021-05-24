#pragma once
#include <string>
#include <filesystem>
#include <memory>
#include <string>
#include <iostream>
#include <map>
#include <fstream>
namespace fs = std::filesystem;

class FileStorageWorker {
public:
    FileStorageWorker(const std::string& Path) : root("/") {
        setDirectory(Path);
    };
    void showCurrentPath();
    void showFileSystemMem(const std::string& Path);
    void showFileInfo(const std::string& Path);
    void setDirectory(const std::string& Path);
    void createDirectory(const std::string& DirName);
    void removeDirectory(const std::string& DirName);
    void removeDirectoryFiles(const std::string& DirName);
    void createFile(const std::string& DirName, const std::string& fileName, const char* buffer, const int64_t& size);
    void removeFileFromDir(const std::string& DirName, const std::string& FileName);
    std::string fileToString(const std::string& DirName, const std::string& FileName);
private:
	fs::path root;
	fs::path currentDir;
    std::map <std::string, fs::path> userPaths;
};