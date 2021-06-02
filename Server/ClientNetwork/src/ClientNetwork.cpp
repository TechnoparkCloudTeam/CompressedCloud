#include "ClientNetwork.h"

ClientNetwork::ClientNetwork(boost::asio::io_service &io_service, std::shared_ptr<IRequestCoordinator> PWPtr_) : socket_(io_service),
                                                                    socketS_(io_service),
                                                                    io_service_(io_service),
                                                                    PWPtr(PWPtr_)
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
    boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string("127.0.0.1"), 8888);

    if (!ec)
    {
        startReadHeaderFS();
    }
    else
    {
        socket_.async_connect(ep, boost::bind(&ClientNetwork::handleConnectFS, this,
                                              boost::asio::placeholders::error));
    }
}
void ClientNetwork::startReadHeaderFS()
{
    m_readbuf_fs.resize(header_size);
    boost::asio::async_read(socket_, boost::asio::buffer(m_readbuf_fs),
                            boost::bind(&ClientNetwork::handleReadHeaderFS, this));
}

void ClientNetwork::handleReadHeaderFS()
{
    unsigned msg_len = headerMenager.decodeHeader(m_readbuf_fs);
    //BOOST_LOG_TRIVIAL(debug) << "MSG LEN: " << msg_len << std::endl;
    startReadBodyFS(msg_len);
}

void ClientNetwork::startReadBodyFS(unsigned msg_len)
{
    m_readbuf_fs.resize(header_size + msg_len);
    boost::asio::mutable_buffers_1 buf = boost::asio::buffer(&m_readbuf_fs[header_size], msg_len);
    boost::asio::async_read(socket_, buf, boost::bind(&ClientNetwork::handleReadBodyFS, this));
}
void ClientNetwork::handleReadBodyFS()
{

    messageFS::Request readed;
    messageFS::Request writeRequest;
    readed.ParseFromArray(&m_readbuf_fs[header_size], m_readbuf_fs.size() - header_size);
    switch (readed.id())
    {
    case ServerFS::OKDOWNLOAD:
    {
        
        std::ofstream file("SynchFolder/" + readed.name() + "/" + readed.filename(), std::ofstream::binary);
        file.write(readed.file().c_str(), readed.filesize());
        file.close();
        PWPtr->add();
        break;
    }
    case ServerFS::OKSENDING:
    {
        writeRequest.set_id(ServerSyncho::ADDFILE);
        writeRequest.set_name(readed.name());
        writeRequest.set_filesize(readed.filesize());
        writeRequest.set_filename(readed.filename());
        writeRequest.set_filepath(readed.filepath());
        writeRequest.set_fileextention(readed.fileextention());
        std::string bufForSerial;
        writeRequest.SerializePartialToString(&bufForSerial);
        writeMessageToS(bufForSerial);
        break;
    }
    case ServerFS::OKDELETE:
    {
        writeRequest.set_id(ServerSyncho::DELETEFILES);
        writeRequest.set_name(readed.name());
        writeRequest.set_filename(readed.filename());
        std::string bufForSerial;
        writeRequest.SerializePartialToString(&bufForSerial);
        writeMessageToS(bufForSerial);
        break;
    }
    default:
        break;
    }
    startReadHeaderFS();
}

void ClientNetwork::writeMessageToFS(const std::string &msg) 
{
    io_service_.post(boost::bind(&ClientNetwork::doWriteFS, this, msg));
}
void ClientNetwork::doWriteFS(std::string &msg)
{
    std::vector<boost::uint8_t> buf(4);
    std::string size = headerMenager.encodeHeader(buf, msg.size());

    msg = size + msg;
    bool write_in_progress = !qWrite.empty();

    qWrite.push_back(msg);
    if (!write_in_progress)
    {
        boost::asio::async_write(socket_, boost::asio::buffer(qWrite.front().data(), qWrite.front().length()),
                                 boost::bind(&ClientNetwork::writeHeandlerFS, this));
    }
}

void ClientNetwork::writeHeandlerFS()
{
    qWrite.pop_front();
    if (!qWrite.empty())
    {
        boost::asio::async_write(socket_, boost::asio::buffer(qWrite.front().data(), qWrite.front().length()),
                                 boost::bind(&ClientNetwork::writeHeandlerS, this));
    }
}

//-------------------------------------------------------------------------------------------
void ClientNetwork::handleConnectS(boost::system::error_code ec)
{
    boost::asio::ip::tcp::endpoint eps(boost::asio::ip::address::from_string("127.0.0.1"), 6666);

    if (!ec)
    {
        startReadHeaderS();
    }
    else
    {
        socketS_.async_connect(eps, boost::bind(&ClientNetwork::handleConnectS, this,
                                                boost::asio::placeholders::error));
    }
}

void ClientNetwork::startReadHeaderS()
{
    m_readbuf_s.resize(header_size);
    boost::asio::async_read(socketS_, boost::asio::buffer(m_readbuf_s),
                            boost::bind(&ClientNetwork::handleReadHeaderS, this));
}

void ClientNetwork::handleReadHeaderS()
{
    unsigned msg_len = headerMenager.decodeHeader(m_readbuf_s);

    //BOOST_LOG_TRIVIAL(debug) << "MSG LEN: " << msg_len << std::endl;
    startReadBodyS(msg_len);
}

void ClientNetwork::startReadBodyS(unsigned msg_len)
{
    m_readbuf_s.resize(header_size + msg_len);
    boost::asio::mutable_buffers_1 buf = boost::asio::buffer(&m_readbuf_s[header_size], msg_len);
    boost::asio::async_read(socketS_, buf, boost::bind(&ClientNetwork::handleReadBodyS, this));
}

void ClientNetwork::handleReadBodyS()
{
    messageFS::Request readed;
    readed.ParseFromArray(&m_readbuf_s[header_size], m_readbuf_s.size() - header_size);
    //std::cout << "Readed from s id: " << readed.id() << " name: " << readed.name() << std::endl;
    switch (readed.id())
    {
    case ServerSyncho::OKREG:
    {
        readed.set_id(ServerFS::CREATEFOLDER);
        std::string answer;
        readed.SerializePartialToString(&answer);
        writeMessageToFS(answer);
        PWPtr->add();
        break;
    }
    case ServerSyncho::OKLOGIN:
    {
        PWPtr->add();
        break;
    }
    case ServerSyncho::BADLOGIN:
    {
        break;
    }
    case ServerSyncho::CHECKFRIENDANDFILESUCCESSFUL:
    {
        readed.set_id(ServerFS::DOWNLOADFILRFRIEND);
        readed.set_name(readed.name()); 
        readed.set_loginfriend(readed.loginfriend());
        std::string answer;
        readed.SerializePartialToString(&answer);
        writeMessageToFS(answer);
        break;
    }
    case ServerSyncho::FRIENDSHIPSUCCESSFUL:
    {
        std::cout<<"Added friend successfully\n";
        break;
    }
    case ServerSyncho::OKSEND:
    {
        break;
    }
    default:
        break;
    }
    startReadHeaderS();
}

void ClientNetwork::writeMessageToS(const std::string &msg) 
{
    io_service_.post(boost::bind(&ClientNetwork::doWriteS, this, msg));
}

void ClientNetwork::doWriteS(std::string &msg)
{
    std::vector<boost::uint8_t> buf(4);
    std::string size = headerMenager.encodeHeader(buf, msg.size());

    msg = size + msg;
    bool write_in_progress = !qWriteS.empty();

    qWriteS.push_back(msg);
    if (!write_in_progress)
    {
        boost::asio::async_write(socketS_, boost::asio::buffer(qWriteS.front().data(), qWriteS.front().length()),
                                 boost::bind(&ClientNetwork::writeHeandlerS, this));
    }
}

void ClientNetwork::writeHeandlerS()
{
    qWriteS.pop_front();
    if (!qWriteS.empty())
    {
        boost::asio::async_write(socketS_, boost::asio::buffer(qWriteS.front().data(), qWriteS.front().length()),
                                 boost::bind(&ClientNetwork::writeHeandlerS, this));
    }
}



