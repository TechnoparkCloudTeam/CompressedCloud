#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "FileStorage.h"
#include "MetaDataBase.h"
#include "Synchronisator.h"
#include "RequestsProcessor.h"
#include "UserAccess.h"

class MockSynchronisator : ISynchronisator {
public:
    MOCK_METHOD0(GetRequest, void());
    MOCK_METHOD0(SendRequest, void());
    MOCK_METHOD0(SendAnswer, void());
    MOCK_METHOD0(CheckForConflicts, void());
    MOCK_METHOD0(GetStatus, void());
};

TEST(FileStorage, SendData) {
    FileStorage fileStorage;
    MockSynchronisator mockSynchronisator;
    fileStorage.SendData();
    EXPECT_CALL(mockSynchronisator, GetRequest()).Times(1);
}

TEST(FileStorage, GetRequest) {
    FileStorage fileStorage;
    MockSynchronisator mockSynchronisator;
    fileStorage.GetRequest();
    EXPECT_CALL(mockSynchronisator, SendRequest()).Times(1);
}

TEST(FileStorage, DEleteFiles) {
    FileStorage fileStorage;
    MockSynchronisator mockSynchronisator;
    fileStorage.DeleteFiles();
    EXPECT_CALL(mockSynchronisator, SendRequest()).Times(1);
}

TEST(FileStorage, MakeDir) {
    FileStorage fileStorage;
    MockSynchronisator mockSynchronisator;
    fileStorage.MakeDir();
    EXPECT_CALL(mockSynchronisator, SendRequest()).Times(1);
}

TEST(FileStorage, GetStatus) {
    FileStorage fileStorage;
    MockSynchronisator mockSynchronisator;
    fileStorage.GetStatus();
    EXPECT_CALL(mockSynchronisator, SendRequest()).Times(1);
}

TEST(MetaDataBase, GetRequest) {
    MetaDataBase metaDataBase;
    MockSynchronisator mockSynchronisator;
    metaDataBase.GetRequest();
    EXPECT_CALL(mockSynchronisator, SendRequest()).Times(1);
}

TEST(MetaDataBase, AddUser) {
    MetaDataBase metaDataBase;
    MockSynchronisator mockSynchronisator;
    metaDataBase.AddUser();
    EXPECT_CALL(mockSynchronisator, SendRequest()).Times(1);
}

TEST(MetaDataBase, CheckUser) {
    MetaDataBase metaDataBase;
    MockSynchronisator mockSynchronisator;
    metaDataBase.CheckUser();
    EXPECT_CALL(mockSynchronisator, SendRequest()).Times(1);
}

TEST(MetaDataBase, DeleteUser) {
    MetaDataBase metaDataBase;
    MockSynchronisator mockSynchronisator;
    metaDataBase.DeleteUser();
    EXPECT_CALL(mockSynchronisator, SendRequest()).Times(1);
}

TEST(MetaDataBase, AddUserToDir) {
    MetaDataBase metaDataBase;
    MockSynchronisator mockSynchronisator;
    metaDataBase.AddUserToDir();
    EXPECT_CALL(mockSynchronisator, SendRequest()).Times(1);
}

TEST(MetaDataBase, UpdateDirInfo) {
    MetaDataBase metaDataBase;
    MockSynchronisator mockSynchronisator;
    metaDataBase.UpdateDirInfo();
    EXPECT_CALL(mockSynchronisator, SendRequest()).Times(1);
}

TEST(MetaDataBase, GetStatus) {
    MetaDataBase metaDataBase;
    MockSynchronisator mockSynchronisator;
    metaDataBase.GetStatus();
    EXPECT_CALL(mockSynchronisator, SendRequest()).Times(1);
}

TEST(MetaDataBase, SendAnswer) {
    MetaDataBase metaDataBase;
    MockSynchronisator mockSynchronisator;
    metaDataBase.SendAnswer();
    EXPECT_CALL(mockSynchronisator, GetRequest()).Times(1);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}

