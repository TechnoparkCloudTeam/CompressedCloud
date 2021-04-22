#pragma once
#include <string>
class IProgramInterface {
public:
	virtual void ReadRequest() = 0;
	virtual void ShowAnswer() = 0;
	virtual void SendRequest() = 0;
};

class ProgramInterface : public IProgramInterface {
public:
	void ReadRequest() override;
	void ShowAnswer() override;
	void SendRequest() override;
private:
	std::string Request;
	std::string Answer;
};