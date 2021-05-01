#include <string>

struct UserInfo {
        std::string login;
        std::string password;
};

class IUserInfoDB {
public:
       virtual int login(const UserInfo &user) = 0;
       virtual int registration(const UserInfo &user) = 0;
};
