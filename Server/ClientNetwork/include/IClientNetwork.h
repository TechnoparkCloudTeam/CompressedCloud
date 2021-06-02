#pragma once

#include <string>

struct IClientNetwork
{
    virtual void writeMessageToFS(const std::string &msg) = 0;

    virtual void writeMessageToS(const std::string &msg) = 0;
};
