#include "ClientNetwork.h"
enum ServerSynchoRead
{
    OKREG = 0,
    REGISTRATION = 1,
    AUTORIZATION = 2,
};

enum ServerFSWrite
{
    
    CREATEFOLDER = 1,
    
};
 ClientNetwork::ClientNetwork(boost::asio::io_service &io_service) : socket_(io_service),
                                                                    socketS_(io_service),
                                                                    socketToSynch(io_service),
                                                                    io_service_(io_service)
{

    boost::asio::ip::tcp::endpoint eps(boost::asio::ip::address::from_string("127.0.0.1"), 6666);
    socketS_.async_connect(eps, boost::bind(&ClientNetwork::handleConnectS, this,
                                           boost::asio::placeholders::error));

    boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string("127.0.0.1"), 8888);
    socket_.async_connect(ep, boost::bind(&ClientNetwork::handleConnectFS, this,
                                          boost::asio::placeholders::error));

}
void ClientNetwork::handleConnectFS(boost::system::error_code ec)
{
    boost::asio::async_read(socket_, boost::asio::buffer(read_data, max_size_buf), boost::asio::transfer_at_least(1),
                            boost::bind(&ClientNetwork::handleReadFS, this, boost::asio::placeholders::error));
}

void ClientNetwork::handleReadFS(boost::system::error_code ec)
{
    std::string readed;
    readed = read_data;
    messageFS::Request answ;
    answ.ParseFromString(readed);
    std::cout << answ.id() << std::endl;
    writeMessageToS(ec,readed);
    boost::asio::async_read(socket_, boost::asio::buffer(read_data, max_size_buf), boost::asio::transfer_at_least(1),
                            boost::bind(&ClientNetwork::handleReadFS, this, boost::asio::placeholders::error));
}

void ClientNetwork::writeMessageToFS(boost::system::error_code ec, const std::string &msg)
{
    io_service_.post(boost::bind(&ClientNetwork::doWriteFS, this, msg));
}

void ClientNetwork::doWriteFS(const std::string &msg)
{
    bool write_in_progress = !qWrite.empty();
    std::copy(msg.begin(), msg.end(), write_data);
    std::string str = write_data;
    qWrite.push_back(write_data);
    std::cout << "wrinprogress " << write_in_progress << std::endl;
    if (!write_in_progress)
    {
        boost::asio::async_write(socket_, boost::asio::buffer(write_data, max_size_buf),
                                 boost::bind(&ClientNetwork::writeHeandlerFS, this));
    }
}

void ClientNetwork::writeHeandlerFS()
{
    qWrite.pop_front();
    std::cout << "qwerty emp: " << qWrite.size() << std::endl;
    if (!qWrite.empty())
    {
        boost::asio::async_write(socket_, boost::asio::buffer(write_data, max_size_buf),
                                 boost::bind(&ClientNetwork::writeHeandlerFS, this));
    }
}
//-------------------------------------------------------------------------------------------
void ClientNetwork::handleConnectS(boost::system::error_code ec)
{
    boost::asio::async_read(socketS_, boost::asio::buffer(read_data, max_size_buf), boost::asio::transfer_at_least(1),
                            boost::bind(&ClientNetwork::handleReadS, this, boost::asio::placeholders::error));
}

void ClientNetwork::handleReadS(boost::system::error_code ec)
{
    messageFS::Request readRequest;
    messageFS::Request writeRequest;
    std::string readed;
    readed = read_data;
    readRequest.ParseFromString(readed);
    std::cout << readRequest.id() << std::endl;
    switch (readRequest.id())
    {
    case ServerSynchoRead::OKREG:
        std::cout<<"ya tut bil";
        writeRequest.set_id(ServerFSWrite::CREATEFOLDER);
        writeRequest.SerializePartialToString(&readed);
        writeMessageToFS(ec, readed);
        break;
    
    default:
        break;
    }
    
    boost::asio::async_read(socketS_, boost::asio::buffer(read_data, max_size_buf), boost::asio::transfer_at_least(1),
                            boost::bind(&ClientNetwork::handleReadS, this, boost::asio::placeholders::error));
}

void ClientNetwork::writeMessageToS(boost::system::error_code ec, const std::string &msg)
{
    io_service_.post(boost::bind(&ClientNetwork::doWriteS, this, msg));
}

void ClientNetwork::doWriteS(const std::string &msg)
{
    bool write_in_progress = !qWriteS.empty();
    std::copy(msg.begin(), msg.end(), write_data);
    std::string str = write_data;
    qWriteS.push_back(write_data);
    std::cout << "wrinprogress " << write_in_progress << std::endl;
    if (!write_in_progress)
    {
        boost::asio::async_write(socketS_, boost::asio::buffer(write_data, max_size_buf),
                                 boost::bind(&ClientNetwork::writeHeandlerS, this));
    }
}

void ClientNetwork::writeHeandlerS()
{
    qWriteS.pop_front();
    std::cout << "qwerty emp: " << qWrite.size() << std::endl;
    if (!qWriteS.empty())
    {
        boost::asio::async_write(socketS_, boost::asio::buffer(write_data, max_size_buf),
                                 boost::bind(&ClientNetwork::writeHeandlerS, this));
    }
} 
