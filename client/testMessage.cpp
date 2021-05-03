

#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include "../message/include/Message.h"


std::vector<char> readFileBytes(const std::string &name) // че то подобное должно быть в чанкере
{
  std::ifstream file(name.c_str());
  file.seekg( 0, file.end );
  size_t len = file.tellg();
  std::vector<char> ret(len);
  file.seekg(0, std::ios::beg);
  if (len)
    file.read(&ret[0], len);
  file.close();
  return move(ret);
}

enum class TestMsgType : uint32_t {
    sendFile,
    sendFileChunk,
    getFile
};

int main() {
    msg::Message<TestMsgType> msg;

    msg.header.id = TestMsgType::sendFile;

    msg.header.userID.login = "Lyalyashechka";

    //получается щас в векторе лежит вектор с файлами
    msg<<readFileBytes("/home/lyalyashechka/TP/c_c++/asio/client/text.txt");
    
    std::cout<<msg;
}