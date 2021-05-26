#pragma once

#include <iostream>
#include <queue>

class PatternWatcher
{
public:
    int waitCancelDownload();
    void add();
private:
    std::queue<int> Q;
};