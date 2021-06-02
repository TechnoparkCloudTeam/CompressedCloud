#pragma once

#include <iostream>
#include <queue>

#include "IRequestCoordinator.h"

class RequestCoordinator : public IRequestCoordinator
{
public:
    int wait() override;
    void add() override;
private:
    std::queue<int> Q;
};
