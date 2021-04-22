#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "FileStorage.h"
#include "UserInfoDB.h"
#include "MetaDB.h"
#include "LocalDB.h"

class MockFileStorage: public FileSTorage {
 public:
  MOCK_METHOD0(connect, void());
};


TEST(MockFileStorage, connect_addChunk_Mock) {
  MockFileStorage fs;

  EXPECT_CALL(fs, connect()).Times(1);
  fs.addChunk();
}

TEST(MockFileStorage, connect_getChunk_Mock) {
  MockFileStorage fs;

  EXPECT_CALL(fs, connect()).Times(1);
  fs.getChunk();
}

class MockUserInfoDB: public UserInfoDB {
 public:
  MOCK_METHOD0(connect, void());
};


TEST(MockUserInfoDB, connect_registration_Mock) {
  MockUserInfoDB udb;

  EXPECT_CALL(udb, connect()).Times(1);
  udb.registration();
}

TEST(MockUserInfoDB, connect_login_Mock) {
  MockUserInfoDB udb;

  EXPECT_CALL(udb, connect()).Times(1);
  udb.login();
}

TEST(MockUserInfoDB, connect_checkPassword_Mock) {
  MockUserInfoDB udb;

  EXPECT_CALL(udb, connect()).Times(1);
  udb.checkPassword();
}

class MockDB: public LocalDB {
 public:
  MOCK_METHOD0(disconnect, void());
  MOCK_METHOD0(connect, bool());
};


TEST(LocalDB, processRequest_Mock) {
  MockDB idb;

  EXPECT_CALL(idb, connect()).Times(1);
  EXPECT_CALL(idb, disconnect()).Times(1);
  idb.processRequest();
}

TEST(LocalDB, getDeviceId_Mock) {
  MockDB idb;

  EXPECT_CALL(idb, connect()).Times(1);
  EXPECT_CALL(idb, disconnect()).Times(1);
  idb.getDeviceId();
}

TEST(LocalDB, addUser_Mock) {
  MockDB idb;

  EXPECT_CALL(idb, connect()).Times(1);
  EXPECT_CALL(idb, disconnect()).Times(1);
  idb.addUser();
}

TEST(LocalDB, deleteUser_Mock) {
  MockDB idb;

  EXPECT_CALL(idb, connect()).Times(1);
  EXPECT_CALL(idb, disconnect()).Times(1);
  idb.deleteUser();
}

TEST(LocalDB, updateSynchFolder_Mock) {
  MockDB idb;

  EXPECT_CALL(idb, connect()).Times(1);
  EXPECT_CALL(idb, disconnect()).Times(1);
  idb.updateSynchFolder();
}


TEST(LocalDB, addFile_Mock) {
  MockDB idb;

  EXPECT_CALL(idb, connect()).Times(1);
  EXPECT_CALL(idb, disconnect()).Times(1);
  idb.addFile();
}

TEST(LocalDB, selectFile_Mock) {
  MockDB idb;

  EXPECT_CALL(idb, connect()).Times(1);
  EXPECT_CALL(idb, disconnect()).Times(1);
  idb.selectFile();
}

TEST(LocalDB, updateFile_Mock) {
  MockDB idb;

  EXPECT_CALL(idb, connect()).Times(1);
  EXPECT_CALL(idb, disconnect()).Times(1);
  idb.updateFile();
}

TEST(LocalDB, addChunks_Mock) {
  MockDB idb;

  EXPECT_CALL(idb, connect()).Times(1);
  EXPECT_CALL(idb, disconnect()).Times(1);
  idb.addChunks();
}

TEST(LocalDB, getChunks_Mock) {
  MockDB idb;

  EXPECT_CALL(idb, connect()).Times(1);
  EXPECT_CALL(idb, disconnect()).Times(1);
  idb.getChunks();
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}

