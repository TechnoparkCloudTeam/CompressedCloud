#include <iostream>
#include "server.h"

int main(int argc, char* argv[]) {
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  fsServer::Server serv(std::atoi(argv[1]));
  serv.run();
  return 0;
}