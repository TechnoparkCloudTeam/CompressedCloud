#pragma once

#include <exception>
#include <string>
#include <utility>

class PostgresExceptions : public std::exception
{
public:
	explicit PostgresExceptions(std::string msg)
			: std::exception(), _msg(std::move(msg))
	{
	}

	const char *what() const noexcept override
	{
		return _msg.c_str();
	}

private:
	std::string _msg;
};
