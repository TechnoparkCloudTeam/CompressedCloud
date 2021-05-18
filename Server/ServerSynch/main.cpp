#include <iostream>
#include "serverSynch.h"
#include "message.pb.h"
#include "../../DataBases/PostgresDB/UserDB/include/UserDB.h"

#include "../../DataBases/PostgresDB/UserDB/include/UserInfo.h"
int main(int argc, char *argv[])
{
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  UsersDB &postgres_sqldb1 = UsersDB::shared("user=lida password=123 dbname=mydb host=127.0.0.1 port=5432");
  postgres_sqldb1.Connect();
  postgres_sqldb1.createTable();
  auto ptr = std::shared_ptr<UsersDB> (&postgres_sqldb1);
  sServer::Server serv(std::atoi(argv[1]), ptr);
  serv.run();
  //io_service_.run();
  return 0;
}