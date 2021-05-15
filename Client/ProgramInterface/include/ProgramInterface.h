#pragma once
#include <string>
#include <memory>
#include <../../Application/include/Application.h>
class IProgramInterface {
public:
	virtual void run() = 0;
};

class ProgramInterface : public IProgramInterface {
public:
	ProgramInterface(std::shared_ptr<Application> app);
	void run() override;
private:
	std::shared_ptr<Application> app;
};