#include <iostream>
#include "serverSynch.h"
#include "message.pb.h"
#include "UserDB.h"
#include "MetaDB.h"
#include "FriendDB.h"
#include "UserInfo.h"

int main(int argc, char *argv[])
{
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  UsersDB &postgres_sqldb1 = UsersDB::shared("user=lida password=123 dbname=mydb host=127.0.0.1 port=5432");
  postgres_sqldb1.Connect();
  postgres_sqldb1.createTable();
  MetaDataDB &postgres_sqldb = MetaDataDB::shared("user=lida password=123 dbname=mydb host=127.0.0.1 port=5432");
  postgres_sqldb.Connect();
  postgres_sqldb.createTable();
  FriendDB &postgres_sqldb2 = FriendDB::shared("user=lida password=123 dbname=mydb host=127.0.0.1 port=5432");
  postgres_sqldb2.Connect();
  postgres_sqldb2.createTable();
  auto ptr = std::shared_ptr<IUserDB> (&postgres_sqldb1);
  auto ptr1 = std::shared_ptr<IMetaDataDB> (&postgres_sqldb);
  auto ptr2 = std::shared_ptr<IFriendDB> (&postgres_sqldb2);
  sServer::Server serv(std::atoi(argv[1]), ptr, ptr1, ptr2);
  serv.run();
  //io_service_.run();
  return 0;
}