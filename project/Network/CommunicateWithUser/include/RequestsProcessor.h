#pragma once
#include <map>

class IRequestsProcessor {
public:
	virtual void Connect() = 0;
	virtual void Disconnect() = 0;
	virtual void SendAnswer() = 0;
	virtual void SendRequest() = 0;
	virtual void GetRequest() = 0;
	virtual void GetRequestType() = 0;
	virtual void GetStatus() = 0;
};

class RequestsProcessor : public IRequestsProcessor {
public:
	void Connect() override;
	void Disconnect() override;
	void Run();
	void ShutDown();
	void GetRequest() override;
	void GetRequestType() override;
	void SendAnswer() override;
	void SendRequest() override;
	void GetStatus() override;
};
