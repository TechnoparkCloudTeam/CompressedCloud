#pragma once
#include <string>

enum AvailableCommands : uint32_t {
	
};

class IClientServerCommunication {
public:
	virtual	void CreateRequest() = 0;
	virtual void SendRequest() = 0;
	virtual void GetAnswer() = 0;
	virtual void GetAnswerType() = 0;
	virtual void GetRequestComponents() = 0;
	virtual void GetStatus() = 0;
};

class ClientServerCommunication : public IClientServerCommunication {
public:
	void CreateRequest() override;
	void SendRequest() override;
	void GetAnswer() override;
	void GetAnswerType() override;
	void GetRequestComponents() override;
	void GetStatus() override;
private:
	void AddLoginPass();
	void Run();
	void ShutDown();
	std::string login;
	std::string password;
	AvailableCommands availableCommands;
};
