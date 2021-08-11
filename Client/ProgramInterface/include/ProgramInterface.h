#pragma once

#include <string>
#include <memory>

#include "Application.h"
#include "IProgramInterface.h"

class ProgramInterface : public IProgramInterface
{
public:
	ProgramInterface(std::shared_ptr<Application> app);
	
	void run() override;

private:
	std::shared_ptr<Application> app;
};