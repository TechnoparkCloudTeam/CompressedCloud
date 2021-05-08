#include <iostream>
#include "server.h"
#include "message.pb.h"
#include "FileStorageWorker.h"

int main(int argc, char* argv[]) {
  FileStorageWorker fs("/home/lyalyashechka/TP/c_c++/main server/build/content");
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  messageFS::Request req;
  req.set_id(1);
  fsServer::Server serv(argv[1]);
  serv.run();
  //io_service_.run();
  return 0;
}