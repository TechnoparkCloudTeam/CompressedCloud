#include <iostream>
#include "server.h"
#include "message.pb.h"
#include "FileStorageWorker.h"

int main(int argc, char* argv[]) {
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  messageFS::Request req;
  req.set_id(1);
  fsServer::Server serv(std::atoi(argv[1]));
  serv.run();
  //io_service_.run();
  return 0;
}