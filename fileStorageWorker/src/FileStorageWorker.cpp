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
                                   const std::string &fileName, const char *buffer)
{
    fs::current_path(root / currentDir / DirName);
    std::ofstream(fileName, std::ios_base::binary) << buffer;
}

void FileStorageWorker::removeFileFromDir(const std::string &DirName, const std::string &FileName)
{
    fs::current_path(root / currentDir / DirName);
    fs::remove(FileName);
}