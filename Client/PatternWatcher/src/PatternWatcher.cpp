#include "PatternWatcher.h"

int PatternWatcher::waitCancelDownload()
{
    while(Q.empty())
    {
    }
    Q.pop();
    return 1;
}

void PatternWatcher::add()
{
    Q.push(1);
}