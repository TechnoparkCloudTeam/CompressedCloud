#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "FileStorage.h"
#include "MetaDataBase.h"
#include "Synchronisator.h"
#include "RequestsProcessor.h"
#include "UserAccess.h"
#include "ClientServerCommunication.h"


class MockFileStorage : IFileStorage{
public:

    MOCK_METHOD0(SendData, void());

    MOCK_METHOD0(GetRequest, void());

    MOCK_METHOD0(DeleteFiles, void());

    MOCK_METHOD0(MakeDir, void());

    MOCK_METHOD0(DeleteDir, void());

    MOCK_METHOD0(GetStatus, void());
};

class MockMetaDataBase : IMetaDataBase {
public:
    MOCK_METHOD0(GetRequest, void());
    MOCK_METHOD0(AddUser, void());
    MOCK_METHOD0(CheckUser, void());
    MOCK_METHOD0(DeleteUser, void());
    MOCK_METHOD0(AddUserToDir, void());
    MOCK_METHOD0(UpdateDirInfo, void());
    MOCK_METHOD0(RemoveUserFromDir, void());
    MOCK_METHOD0(GetStatus, void());
    MOCK_METHOD0(SendAnswer, void());

};

TEST(Synchronisator, GetRequest) {
    Synchronisator synchronisator;
    MockFileStorage mockFileStorage;
    synchronisator.GetRequest();
    EXPECT_CALL(mockFileStorage, SendData).Times(1);
}

TEST(Synchronisator, SendRequest) {
    Synchronisator synchronisator;
    MockFileStorage mockFileStorage;
    synchronisator.SendRequest();
    EXPECT_CALL(mockFileStorage, GetRequest).Times(1);
}


class MockUserAccess : IUserAccess {
public:
    MOCK_METHOD0(GetRequest, void());
    MOCK_METHOD0(SendAnswer, void());
    MOCK_METHOD0(ProccessRequest, void());
    MOCK_METHOD0(SendRequest, void());
    MOCK_METHOD0(GetStatus, void());
};

TEST(Synchronisator, SendRequestToUserConnection) {
    Synchronisator synchronisator;
    MockUserAccess userAccess;
    synchronisator.SendRequest();
    EXPECT_CALL(userAccess, GetRequest).Times(1);
}

TEST(Synchronisator, GetStatus) {
    Synchronisator synchronisator;
    MockUserAccess userAccess;
    synchronisator.GetStatus();
    EXPECT_CALL(userAccess, SendRequest).Times(1);
}

TEST(Synchronisator, CheckForConflicts) {
    Synchronisator synchronisator;
    MockUserAccess userAccess;
    MockMetaDataBase metaDataBase;
    MockFileStorage filestorage;
    synchronisator.CheckForConflicts();
    EXPECT_CALL(userAccess, SendRequest).Times(1);
    EXPECT_CALL(metaDataBase, SendAnswer).Times(1);
    EXPECT_CALL(filestorage, SendData()).Times(1);

}

class MockRequestsProcessor : public IRequestsProcessor {
public:
	MOCK_METHOD0(Connect, void());
	MOCK_METHOD0(Disconnect, void());
	MOCK_METHOD0(SendAnswer, void());
	MOCK_METHOD0(SendRequest, void());
	MOCK_METHOD0(GetRequest, void());
	MOCK_METHOD0(GetRequestType, void());
	MOCK_METHOD0(GetStatus, void());
};

TEST(UserAccess, GetRequest) {
    MockRequestsProcessor requestsProcessor;
    UserAccess userAccess;
    userAccess.GetRequest();
    EXPECT_CALL(requestsProcessor, SendRequest);
}

TEST(UserAccess, SendAnswer_ProcessRequest) {
    MockMetaDataBase metaData;
    MockRequestsProcessor requestsProcessor;
    UserAccess userAccess;
   
    EXPECT_CALL(metaData, SendAnswer);
    userAccess.GetRequest();
    userAccess.ProccessRequest();
    EXPECT_CALL(requestsProcessor, GetRequest);   
}

class MockSynchronisator : ISynchronisator {
public:
    MOCK_METHOD0(GetRequest, void());
    MOCK_METHOD0(SendRequest, void());
    MOCK_METHOD0(SendAnswer, void());
    MOCK_METHOD0(CheckForConflicts, void());
    MOCK_METHOD0(GetStatus, void());
};

TEST(RequestProcessor, Connect) {
    MockSynchronisator mockSynchro;
    RequestsProcessor requestProcessor;
    requestProcessor.Connect();
    EXPECT_CALL(mockSynchro, GetRequest);
    
}

TEST(RequestProcessor, Disconnect) {
    MockSynchronisator mockSynchro;
    RequestsProcessor requestProcessor;
    requestProcessor.Disconnect();
    EXPECT_CALL(mockSynchro, GetRequest);
}

TEST(RequestProcessor, SendRequest) {
    MockSynchronisator mockSynchro;
    RequestsProcessor requestProcessor;
    requestProcessor.SendRequest();
    EXPECT_CALL(mockSynchro, GetRequest);
    
}
TEST(RequestProcessor, GetRequestFromUserAccess) {
    MockUserAccess userAccess;
    RequestsProcessor requestProcessor;
    requestProcessor.GetRequest();
    EXPECT_CALL(userAccess, SendAnswer);
    
}

class MockClientServerCommunication : public IClientServerCommunication{
public:
    MOCK_METHOD0(CreateRequest, void());
    MOCK_METHOD0(SendRequest, void());
    MOCK_METHOD0(GetAnswer, void());
    MOCK_METHOD0(GetAnswerType, void());
    MOCK_METHOD0(GetRequestComponents, void());
    MOCK_METHOD0(GetStatus, void());
};

TEST(RequestProcessor, ConnectWithUser) {
    MockClientServerCommunication ClientServerCommunication;
    RequestsProcessor requestProcessor;
    requestProcessor.Connect();
    EXPECT_CALL(ClientServerCommunication, SendRequest);
}

TEST(RequestProcessor, DisconnectFromUser) {
    MockClientServerCommunication ClientServerCommunication;
    RequestsProcessor requestProcessor;
    requestProcessor.Disconnect();
    EXPECT_CALL(ClientServerCommunication, SendRequest);
}

TEST(RequestProcessor, SendAnswerToUser) {
    MockClientServerCommunication ClientServerCommunication;
    RequestsProcessor requestProcessor;
    EXPECT_CALL(ClientServerCommunication, SendRequest);
    requestProcessor.SendAnswer();
    EXPECT_CALL(ClientServerCommunication, GetAnswer);
    EXPECT_CALL(ClientServerCommunication, GetAnswerType);
}

TEST(RequestProcessor, GetRequestFromUser) {
    MockClientServerCommunication ClientServerCommunication;
    RequestsProcessor requestProcessor;
    EXPECT_CALL(ClientServerCommunication, SendRequest);
    requestProcessor.GetRequest();
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}

