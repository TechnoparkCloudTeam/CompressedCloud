#include "PatternWatcher.h"

int PatternWatcher::waitCancelDownload()
{
    int i = 0;
    while(Q.empty())
    {
        i++;
    }
    Q.pop();
    return 1;
}

void PatternWatcher::add()
{
    Q.push(1);
}