#include <iostream>
#include "serverSynch.h"
#include "message.pb.h"
#include "../../DataBases/PostgresDB/UserDB/include/UserDB.h"
#include "MetaDB.h"

#include "../../DataBases/PostgresDB/UserDB/include/UserInfo.h"
int main(int argc, char *argv[])
{
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  UsersDB &postgres_sqldb1 = UsersDB::shared("user=lida password=123 dbname=mydb host=127.0.0.1 port=5432");
  postgres_sqldb1.Connect();
  postgres_sqldb1.createTable();
  MetaDataDB &postgres_sqldb = MetaDataDB::shared("user=lida password=123 dbname=mydb host=127.0.0.1 port=5432");
  postgres_sqldb.Connect();
  postgres_sqldb.createTable();
  auto ptr = std::shared_ptr<UsersDB> (&postgres_sqldb1);
  auto ptr1 = std::shared_ptr<MetaDataDB> (&postgres_sqldb);
  sServer::Server serv(std::atoi(argv[1]), ptr, ptr1);
  serv.run();
  //io_service_.run();
  return 0;
}