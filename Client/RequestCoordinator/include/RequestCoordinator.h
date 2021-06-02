#pragma once

#include <iostream>
#include <queue>

#include "IRequestCoordinator.h"

class RequestCoordinator : public IRequestCoordinator
{
public:
    int wait() override;
    void add(const int& status) override;
private:
    std::queue<int> Q;
};
