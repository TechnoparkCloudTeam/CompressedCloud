#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "FileStorage.h"
#include "MetaDataBase.h"
#include "Synchronisator.h"
#include "RequestsProcessor.h"
#include "UserAccess.h"



class MockFileStorage : IFileStorage{
public:

    MOCK_METHOD0(SendData, void());

    MOCK_METHOD0(GetRequest, void());

    MOCK_METHOD0(DeleteFiles, void());

    MOCK_METHOD0(MakeDir, void());

    MOCK_METHOD0(DeleteDir, void());

    MOCK_METHOD0(GetStatus, void());
}

TEST(Synchronisator, GetRequest) {
    Synchronisator synchronisator;
    MockFileStorage mockFileStorage;
    synchronisator.GetRequest();
    EXPECT_CALL(mockFileStorage, SendRequest).Time(1);
}

TEST(Synchronisator, SendRequest) {
    Synchronisator synchronisator;
    MockFileStorage mockFileStorage;
    synchronisator.SendRequest();
    EXPECT_CALL(mockFileStorage, GetRequest).Time(1);
}


class MockUserAccess : IUserAccess {
public:
    MOCK_METHOD0(GetRequest, void());
    MOCK_METHOD0(SendAnswer, void());
    MOCK_METHOD0(ProccessRequest, void());
    MOCK_METHOD0(SendRequest, void());
    MOCK_METHOD0(GetStatus, void());
}

TEST(Synchronisator, SendRequestToUserConnection) {
    Synchronisator synchronisator;
    MockUserAccess userAccess;
    synchronisator.SendRequest();
    EXPECT_CALL(userAccess, GetRequest).Time(1);
}

TEST(Synchronisator, GetStatus) {
    Synchronisator synchronisator;
    MockUserAccess userAccess;
    synchronisator.GetStatus();
    EXPECT_CALL(userAccess, SendRequest).Time(1);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}
