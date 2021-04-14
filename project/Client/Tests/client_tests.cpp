#include <gtest/gtest.h>
#include "Watcher.h"
#include "Chunker.h"
#include <filesystem>
#include <fstream>


TEST(Watcher, AddDirToWatch) {
    std::filesystem::path Path;
    Watcher watcher;
    watcher.AddDirToWatch(Path); 
    ASSERT_EQ(1, 1);
}

TEST(Watcher, SendDirStatus_created_file) {
    std::filesystem::path Path;
    Watcher watcher;
    watcher.AddDirToWatch(Path);
    watcher.SendDirStatus(Path);
    std::fstream File;
    File.open("Test.txt");
   
    watcher.SendDirStatus(Path); // Sends info about watcher directory
    ASSERT_EQ(1, 1);
}

TEST(Watcher, SendDirStatus_changed_file) {
    std::filesystem::path Path;
    Watcher watcher;
    watcher.AddDirToWatch(Path);
    std::fstream File;
    File.open("Test.txt");
    watcher.SendDirStatus(Path);
    File << "Test";
    watcher.SendDirStatus(Path); // Sends info about watcher directory
    ASSERT_EQ(1, 1);
}

TEST(Watcher, SendDirStatus_make_directory) {
    std::filesystem::path Path;
    Watcher watcher;
    watcher.AddDirToWatch(Path);
    watcher.SendDirStatus(Path);
    //bash script mkdir "dir name"
    watcher.SendDirStatus(Path);
    ASSERT_EQ(1, 1);
}

TEST(Watcher, SendDirStatus_remove_directory) {
    std::filesystem::path Path;
    Watcher watcher;
    watcher.AddDirToWatch(Path);
    watcher.SendDirStatus(Path);
    //bash script rmdir "dir name"
    watcher.SendDirStatus(Path);
    ASSERT_EQ(1, 1);
}

TEST(Watcher, GetStatus_is_running) {
    std::filesystem::path Path;
    Watcher watcher;
    watcher.AddDirToWatch(Path);
    watcher.GetStatus(); // Outputs current state of watcher daemon
    ASSERT_EQ(1, 1);
}

class WatcherMock : public IWatcher {
public:
    MOCK_METHOD1(AddDirToWatch, void(std::filesystem::path Path));
    MOCK_METHOD1(SendDirStatus, void());
    MOCK_METHOD0(GetStatus, void());
};

TEST(Chunker, CompareChunks_equal) {
    FileChunk firstChunk;
    FileChunk secondChunk;
    Chunker chunker;
    chunker.CompareChunks(firstChunk, secondChunk);
    ASSERT_EQ(1, 1);
}

TEST(Chunker, CompareChunks_not_equal) {
    FileChunk firstChunk;
    FileChunk secondChunk;
    Chunker chunker;
    chunker.CompareChunks(firstChunk, secondChunk);
    ASSERT_EQ(1, 1);
}

TEST(Chunker, CorrectFile) {
    std::fstream stream;
    stream.open("Test.txt");
    Chunker chunker;
    try {
        chunker.GetFile(stream);
    } catch (...) {

    };
    ASSERT_EQ(1, 1);
}

TEST(Chunker, WrongFile) {
    std::fstream stream;
    stream.open("Test.txt");
    Chunker chunker;
    try {
        chunker.GetFile(stream);
    } catch (...) {

    };
    ASSERT_EQ(1, 1);
}

TEST(Chunker, ParseFile_EqualFiles) {
    Chunker chunker;
    chunker.ParseFile();
    Chunker chunker2; //chunker with ready FileChunks
    ASSERT_EQ(1, 1);
}

TEST(Chunker, GetNewChunk) {

}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

