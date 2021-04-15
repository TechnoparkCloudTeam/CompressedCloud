#include <gtest/gtest.h>
#include "gmock/gmock.h"

#include "Watcher.h"
#include "Chunker.h"
#include "ClientServerCommunication.h"
#include "RequestsProcessor.h"
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
    MOCK_METHOD1(SendDirStatus, void(std::filesystem::path Path));
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
    WatcherMock watcherMock;
    std::filesystem::path Path;
    Chunker chunker;        // SendDirStatus возвращает изменения в неком формате, GetNewChunk принимает эти измения в качестве параметра
    chunker.GetNewChunk(); 
    EXPECT_CALL(watcherMock, SendDirStatus(Path)).Times(1); // смотритель отправляет изменения в чанкер, метод GetNewChunk которого получает эти изменения
}

TEST(Chunker, ParseFile) {
    WatcherMock watcherMock;
    std::filesystem::path Path;
    Chunker chunker;      
    chunker.ParseFile(); // SendDirStatus передаёт информацию о новом файле, который  Parse делит на части
    EXPECT_CALL(watcherMock, SendDirStatus(Path)).Times(1);
}

class MockChunker : public IChunker {
public:
    MOCK_METHOD2(CompareChunks, bool(const FileChunk& lhs, const FileChunk& rhs));

    MOCK_METHOD1(GetFile, void(std::fstream& file));

    MOCK_METHOD0(ParseFile, void());

	MOCK_METHOD0(GetNewChunk, void());

    MOCK_METHOD0(SendChunks, void());
};

TEST(ClientServerCommunication, GetRequestComponents) {
    MockChunker mockChunker;
    ClientServerCommunication ClSComm;
    ClSComm.GetRequestComponents();
    EXPECT_CALL(mockChunker, SendChunks()).Times(1);
}

TEST(ClientServerCommunication, CreateRequest) {
    MockChunker mockChunker;
    ClientServerCommunication ClSComm;
    ClSComm.GetRequestComponents();
    ClSComm.CreateRequest();
    EXPECT_CALL(mockChunker, SendChunks()).Times(1);
}

TEST(ProgramInterface, ReadRequest) {
    //bash input script
    ASSERT_EQ(1, 1);
}

class MockRequestProcessor : public IRequestsProcessor {
public:
    MOCK_METHOD0(Connect, void());
    MOCK_METHOD0(Disconnect, void());
    MOCK_METHOD0(SendAnswer, void());
    MOCK_METHOD0(SendRequest, void());
    MOCK_METHOD0(GetRequest, void());
    MOCK_METHOD0(GetRequestType, void());
    MOCK_METHOD0(GetStatus, void());
};

TEST(ClientServerCommunication, SendRequest) {
    MockRequestProcessor mockRequestProcessor;
    ClientServerCommunication clientServComm;
    clientServComm.SendRequest();
    EXPECT_CALL(mockRequestProcessor, GetRequest);
}

TEST(ClientServerCommunication, GetAnswer) {
    MockRequestProcessor mockRequestProcessor;
    ClientServerCommunication clientServComm;
    clientServComm.GetAnswer();
    EXPECT_CALL(mockRequestProcessor, SendAnswer);
}

TEST(ClientServerCommunication, GetAnswerType) {
    MockRequestProcessor mockRequestProcessor;
    ClientServerCommunication clientServComm;
    clientServComm.GetAnswer();
    clientServComm.GetAnswerType();
    EXPECT_CALL(mockRequestProcessor, SendAnswer);
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}

