#include "FileStorageWorker.h"

void FileStorageWorker::showCurrentPath()
{
    std::cout << "Current path: " << std::filesystem::current_path() << "\n";
}

void FileStorageWorker::showFileSystemMem(const std::string &Path)
{
    auto root = std::filesystem::path(Path);
    auto space = std::filesystem::space(root);
    std::cout << "Total    : " << space.capacity / 1024 / 1024 / 1024 << "GB\n";
    std::cout << "Free     : " << space.free / 1024 / 1024 / 1024 << "GB\n";
    std::cout << "Available: " << space.available / 1024 / 1024 / 1024 << "GB\n";
}

void FileStorageWorker::showFileInfo(const std::string &Path)
{
    std::filesystem::path aPath{Path};
    std::cout << "Path to file:" << aPath << "\n";
    std::cout << "Parent path: " << aPath.parent_path() << "\n";
    std::cout << "File name:   " << aPath.filename() << "\n";
    std::cout << "Extension:   " << aPath.extension() << "\n";
}

void FileStorageWorker::setDirectory(const std::string &Path)
{
    currentDir = Path;
    fs::current_path(root / currentDir);
}

void FileStorageWorker::createDirectory(const std::string &DirName)
{
    fs::create_directory(DirName);
}

void FileStorageWorker::removeDirectory(const std::string &DirName)
{
    fs::remove(DirName);
}
void FileStorageWorker::removeDirectoryFiles(const std::string &DirName)
{
    fs::remove_all(DirName);
}

void FileStorageWorker::createFile(const std::string &DirName,
    const std::string &fileName, const char* buffer, const int64_t& size)
{
    fs::current_path(root / currentDir / DirName);
    //std::ofstream(fileName, std::ios_base::binary) << buffer;
    std::ofstream stream(fileName, std::ofstream::binary);
    stream.write(buffer, size);
}

void FileStorageWorker::removeFileFromDir(const std::string &DirName, const std::string &FileName)
{
    fs::current_path(root / currentDir / DirName);
    fs::remove(FileName);
}

std::string FileStorageWorker::fileToString(const std::string& DirName, const std::string& FileName) {
    fs::current_path(root / currentDir / DirName);
    std::ifstream inputStream(FileName, std::ofstream::binary) ;
    inputStream.seekg(0, inputStream.end);
    long size = inputStream.tellg();
    inputStream.seekg(0);
    char* buffer = new char[size];
    inputStream.read(buffer, size);
    std::string stringBuffer(buffer, size);
    delete buffer;
    return stringBuffer;
}