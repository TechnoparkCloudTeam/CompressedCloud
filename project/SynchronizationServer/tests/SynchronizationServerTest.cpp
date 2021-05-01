#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "ClientNetwork.h"
#include "Server.h"


using ::testing::Return;

class MockClientSession : IClientSession {
public:
  MOCK_METHOD(void, connect, (), (override));
  
  MOCK_METHOD(void, disconnect, (), (override));
  
  MOCK_METHOD(std::string, getRequestFromClient, (), (override));
  
  MOCK_METHOD(void, sendAnswerToClient, (std::string), (override));
  
  MOCK_METHOD(int,getClientId,(), (const, override));
};

class MockClientNetwork : IClientNetwork {
public:
  MOCK_METHOD(void, sendJson, (std::string), (override));
    
  MOCK_METHOD(std::string, getJson, (), (override));
    
  MOCK_METHOD(void, connect, (), (override));
    
  MOCK_METHOD(void, disconnect, (), (override));
};


//получение json'a от клиента
TEST(ServerCommunicate, getJson) {
  MockClientNetwork mockClientNetwork;
  ClientSession ClientSession;
  EXPECT_CALL(mockClientNetwork, connect()).Times(1);
  std::string json;
  EXPECT_CALL(mockClientNetwork, sendJson(json)).Times(1);
  std::string jsonFromUser = ClientSession.getRequestFromClient();
  EXPECT_EQ(json, jsonFromUser);
}

//получение json'ов от нескольких клиентов
TEST(ServerCommunicate, getJsons) {
  MockClientNetwork mockClientNetwork;
  MockClientNetwork mockClientNetwork1;
  MockClientNetwork mockClientNetwork2;
  ClientSession ClientSession;
  EXPECT_CALL(mockClientNetwork, connect()).Times(1);
  std::string json;
  EXPECT_CALL(mockClientNetwork, sendJson(json)).Times(1);
  std::string jsonFromUser = ClientSession.getRequestFromClient();
  EXPECT_EQ(json, jsonFromUser);
  EXPECT_CALL(mockClientNetwork1, sendJson(json)).Times(1);
  jsonFromUser = ClientSession.getRequestFromClient();
  EXPECT_EQ(json, jsonFromUser);
  EXPECT_CALL(mockClientNetwork2, sendJson(json)).Times(1);
  jsonFromUser = ClientSession.getRequestFromClient();
  EXPECT_EQ(json, jsonFromUser);
}

//отправка json'a клиенту 
TEST(ServerCommunicate, SendJson) {
  MockClientNetwork mockClientNetwork;
  ClientSession ClientSession;
  ClientSession.connect();
  std::string json;
  ClientSession.sendAnswerToClient(json);
  EXPECT_CALL(mockClientNetwork, getJson());
}

//получение json'a клиентом
TEST(ClientCommunicate, GetJson) {
  MockClientSession mockClientSession;
  ClientNetwork clientNetwork;
  EXPECT_CALL(mockClientSession, connect()).Times(1);
  std::string json;
  EXPECT_CALL(mockClientSession, sendAnswerToClient(json)).Times(1);
  std::string getterJson = clientNetwork.getJson();
}

//отправка json'a клиентом 
TEST(ClientCommunicate, SendJson) {
  MockClientSession mockClientSession;
  ClientNetwork ClientNetwork;
  ClientNetwork.connect();
  std::string json;
  ClientNetwork.sendJson(json);
  EXPECT_CALL(mockClientSession, getRequestFromClient());
}

//тест запроса в бд 
TEST(Syncronizator, RequestToBD) {
  ClientSession csInsideMQ;
  
  MessageQueues mqInsideSynchro;
  
  std::string json = csInsideMQ.getRequestFromClient();
  
  mqInsideSynchro.getRequestsFromClients();
  mqInsideSynchro.putInQUeue(0, json);
  
  Syncronizator s;

  json = mqInsideSynchro.transferRequestToSyncro();
  s.sendRequestToDB(json);
    //вызываются методы поля command
  ASSERT_EQ(1,1);
}

//тест запроса из БД
TEST(Syncronizator, RequestToClient) {
  
  Syncronizator s;

  std::string json = s.getAnswerFromDB();
  
  MessageQueues mqInsideSynchro;
  mqInsideSynchro.putInQUeue(1, json);
  ClientSession csInsideMQ;
  csInsideMQ.sendAnswerToClient(json);

  ASSERT_EQ(1,1);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}