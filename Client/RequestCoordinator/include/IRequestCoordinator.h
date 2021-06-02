struct IRequestCoordinator
{
    virtual int wait() = 0;
    virtual void add() = 0;
};
