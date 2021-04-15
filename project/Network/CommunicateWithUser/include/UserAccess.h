#pragma once
#include <string>
#include <vector>
#include <queue>

struct json {

};

class IUserAccess {
public:

	virtual void GetRequest() = 0;

	virtual void SendAnswer() = 0;

	virtual void ProccessRequest() = 0;

	virtual void SendRequest() = 0;

	virtual void GetStatus() = 0;

};

class UserAccess : public IUserAccess {
public:

	void GetRequest() override;

	void SendAnswer() override;

	void ProccessRequest() override; // json parser inside

	void SendRequest() override;

	void GetStatus() override;
	
private:
	void Run();
	void ShutDown();
	json RequestData;
};





