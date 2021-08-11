#include <gtest/gtest.h>
#include "gmock/gmock.h"

#include "Watcher.h"
#include "Chunker.h"
#include "Application.h"
#include "Indexer.h"
#include "ProgramInterface.h"
#include <filesystem>
#include <fstream>

bool operator==(FileMeta lhs, FileMeta rhs)
{
    return false;
}

class WatcherMock : public IWatcher
{
public:
    MOCK_METHOD1(run, void(std::filesystem::path Path));
    MOCK_METHOD0(isWorking, bool());
    MOCK_METHOD0(shutdown, void());
};

class ChunkerMock : public IChunker
{
public:
    MOCK_METHOD1(chunkFile, std::vector<FileChunk>(std::filesystem::path Path));
    MOCK_METHOD1(updateFileChunks, void(std::filesystem::path Path));
    MOCK_METHOD1(buildFile, void(std::vector<FileChunk> fileChunks));
};

class IndexerMock : public I_Indexer
{
public:
    MOCK_METHOD2(createFile, FileMeta(const std::filesystem::path &path, size_t chunksCnt));
    MOCK_METHOD2(modifyFile, FileMeta(const std::filesystem::path &path, size_t chunksCnt));
    MOCK_METHOD2(renameFile, FileMeta(const std::filesystem::path &oldPath,
                                      const std::filesystem::path &newPath));
    MOCK_METHOD1(deleteFile, FileMeta(const std::filesystem::path &path));
    MOCK_METHOD1(getFileInfo, FileMeta(const std::filesystem::path &path));
};

class ProgramInterfaceMock : public IProgramInterface
{
public:
    MOCK_METHOD0(ReadRequest, void());
    MOCK_METHOD0(SendRequest, void());
    MOCK_METHOD0(ShowAnswer, void());
};

TEST(Indexer, createFile)
{
    LocalDB tmp;
    Indexer indexer(tmp);
    int Chunks_cnt = 0;
    std::filesystem::path Path;
    FileMeta smth;
    ChunkerMock chunkerMock;
    ASSERT_TRUE(indexer.createFile(Path, Chunks_cnt) == smth);
    EXPECT_CALL(chunkerMock, chunkFile(Path)).Times(1);
}

TEST(Indexer, deleteFile)
{
    LocalDB tmp;
    Indexer indexer(tmp);
    int Chunks_cnt = 0;
    std::filesystem::path Path;
    FileMeta smth;
    ChunkerMock chunkerMock;
    ASSERT_TRUE(indexer.createFile(Path, Chunks_cnt) == smth);
    EXPECT_CALL(chunkerMock, chunkFile(Path)).Times(1);
}

TEST(Indexer, modifyFile)
{
    LocalDB tmp;
    Indexer indexer(tmp);
    int Chunks_cnt = 0;
    std::filesystem::path Path;
    FileMeta smth;
    ChunkerMock chunkerMock;
    ASSERT_TRUE(indexer.modifyFile(Path, Chunks_cnt) == smth);
    EXPECT_CALL(chunkerMock, chunkFile(Path)).Times(1);
}

TEST(Indexer, renameFile)
{
    LocalDB tmp;
    Indexer indexer(tmp);
    std::filesystem::path Path;
    std::filesystem::path newPath;
    FileMeta smth;
    ChunkerMock chunkerMock;
    ASSERT_TRUE(indexer.renameFile(Path, newPath) == smth);
    EXPECT_CALL(chunkerMock, chunkFile(Path)).Times(1);
}

TEST(Indexer, getFileInfo)
{
    LocalDB tmp;
    Indexer indexer(tmp);
    std::filesystem::path Path;
    std::filesystem::path newPath;
    FileMeta smth;
    ChunkerMock chunkerMock;
    ASSERT_TRUE(indexer.getFileInfo(Path) == smth);
    EXPECT_CALL(chunkerMock, chunkFile(Path)).Times(1);
}

TEST(Application, Requests)
{
    Application app;

    IndexerMock indexer;
    ProgramInterfaceMock interface;
    std::filesystem::path Path;
    std::filesystem::path newPath;
    EXPECT_CALL(interface, SendRequest).Times(1);
    app.renameFile();
    EXPECT_CALL(indexer, renameFile(Path, newPath)).Times(1);

    EXPECT_CALL(interface, SendRequest).Times(1);
    app.deleteFile();
    EXPECT_CALL(indexer, deleteFile(Path)).Times(1);
    EXPECT_CALL(interface, SendRequest).Times(1);
    app.createFile();
    int chunkCnt = 0;
    EXPECT_CALL(indexer, createFile(Path, chunkCnt)).Times(1);

    EXPECT_CALL(interface, SendRequest).Times(1);
    app.listeningWatcher();
    WatcherMock watcher;
    EXPECT_CALL(watcher, isWorking).Times(1);
    EXPECT_CALL(interface, SendRequest).Times(1);
    app.registerUser();
    EXPECT_CALL(indexer, createFile(Path, chunkCnt)).Times(1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
