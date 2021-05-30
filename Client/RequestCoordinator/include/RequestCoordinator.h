#pragma once

#include <iostream>
#include <queue>

class RequestCoordinator
{
public:
    int waitCancelDownload();
    void add();
private:
    std::queue<int> Q;
};
