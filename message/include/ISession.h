namespace connection
{
    class ISession
    {
    public:
        virtual ~ISession() = 0;
        virtual void connect() = 0;
        virtual void disconnect() = 0;
        virtual void isConnect() const = 0;
    };

}