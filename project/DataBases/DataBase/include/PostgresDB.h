#include <string>

class PostgresDB {
public:
        void connect();
protected:
     // PGconn *connection;
        std::string connectionInfo;
        void executeQuery(const std::string query);
private:
        void close();
};
