#include <iostream>
#include "server.h"
#include "message.pb.h"
int main(int argc, char* argv[]) {
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  messageFS::Request req;
  req.set_id(1);
  boost::asio::io_service io_service_;
  fsServer::Server serv(argv[1]);
  serv.run();
  //io_service_.run();
  return 0;
}