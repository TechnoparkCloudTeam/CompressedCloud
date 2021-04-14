#pragma once
#include <string>
class IProgramInterface {
public:
	virtual void ReadRequest();
	virtual void ShowAnswer();
	virtual void SendRequest();
};

class ConsoleInterface : public IProgramInterface {
public:
	void ReadRequest() override;
	void ShowAnswer() override;
	void SendRequest();
private:
	
	std::string Request;
};