#pragma once
#include <memory>
#include <string>

struct User
{
	int userId{};
	std::string login;
	std::string password;
	int deviceId{};
	std::string deviceName;
	std::string synchFolder;
	std::string lastUpdate;
};
