#include "../include/Indexer.h"
#include <iostream>

std::string GetCurrentTime()
{
    auto ttime = time(nullptr);
    auto *local_time = localtime(&ttime);
    std::string lastTMPUpdate = std::to_string(1900 + local_time->tm_year) + 
    "-" + std::to_string(1 + local_time->tm_mon) + "-" + std::to_string(local_time->tm_mday) +
     " " + std::to_string(local_time->tm_hour) + ":" + std::to_string(local_time->tm_min) + ":" + std::to_string(local_time->tm_sec);
    return lastTMPUpdate;
}

std::string GetDirStartingFromBuild(const std::filesystem::path& path) {
    std::string dir = path;
	return dir.substr(dir.find("build") + 5);
}
Indexer::Indexer (std::shared_ptr<FileDB> FileDataBase, std::shared_ptr<UserDB> UserDataBase) : 
    LocalFileDataBase(FileDataBase),
    LocalUserDataBase(UserDataBase) {
}

void Indexer::createFile(const std::filesystem::path& path) {
    FileMeta fileInfo = GetFileInfo(path);
    LocalFileDataBase->addFile(fileInfo);
}

 void Indexer::deleteFile(const std::filesystem::path& path) {
     LocalFileDataBase->deleteFile(path.filename(), path);
 }

 void Indexer::AddUser(const std::string& UserLogin, const std::string& UserPassword) {
     User user;
     user.deviceName = "PC";
     user.synchFolder = UserLogin;
     user.login = UserLogin;
     user.password = UserPassword;
     LocalUserDataBase->addUser(user);
 }

 void Indexer::modifyFile(const std::filesystem::path& path, size_t chunksCnt) {
     FileMeta fileInfo;
     fileInfo.chunksCount = chunksCnt;
     fileInfo.version++;
     fileInfo.fileName = path.filename();
     fileInfo.isDownload = false;
     fileInfo.fileSize = std::filesystem::file_size(path);
     fileInfo.updateDate = GetCurrentTime();
     LocalFileDataBase->updateFile(fileInfo);
 }

 FileMeta Indexer::GetFileInfo(const std::filesystem::path& path) {
    FileMeta fileInfo;
    fileInfo.chunksCount = 1;
    fileInfo.fileName = path.filename();
    fileInfo.isDownload = false;
    fileInfo.version = 1;
    fileInfo.fileSize = std::filesystem::file_size(path);
    fileInfo.updateDate = GetCurrentTime();
    fileInfo.createDate = GetCurrentTime();
    fileInfo.fileExtention = path.extension();
    fileInfo.filePath = path;
    return fileInfo;
 }