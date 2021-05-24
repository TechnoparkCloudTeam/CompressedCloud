#include <iostream>
#include "connectionSynch.h"
#include "PostgreSQLDB.h"
#include "../../../../DataBases/PostgresDB/UserDB/include/UserDB.h"
#include "../../../../DataBases/PostgresDB/MetaDB/include/MetaDB.h"
#include "../../../../DataBases/PostgresDB/UserDB/include/UserInfo.h"
#include "../../../../DataBases/PostgresDB/MetaDB/include/FileInfo.h"
#include "../../../config.h"
#define header_size 4
unsigned decode_header(std::vector<boost::uint8_t> &buf)
{
    unsigned msg_size = 0;
    for (unsigned i = 0; i < header_size; ++i)
        msg_size = msg_size * 256 + (static_cast<unsigned>(buf[i]) & 0xFF);
    return msg_size;
}
std::string encode_header(std::vector<boost::uint8_t> &buf, unsigned size)
{
    buf[0] = static_cast<boost::uint8_t>((size >> 24) & 0xFF);
    buf[1] = static_cast<boost::uint8_t>((size >> 16) & 0xFF);
    buf[2] = static_cast<boost::uint8_t>((size >> 8) & 0xFF);
    buf[3] = static_cast<boost::uint8_t>(size & 0xFF);
    std::string sizeStr(buf.begin(), buf.end());
    return sizeStr;
}
Connection::Connection(boost::asio::ip::tcp::socket socket_, std::shared_ptr<UsersDB> postgres_sqldb12, std::shared_ptr<MetaDataDB> postgres_sqldb_file)
    : socket_(std::move(socket_)),
      postgres_sqldb1(postgres_sqldb12),
      postgres_sqldb_file(postgres_sqldb_file)
{
}

void Connection::stop()
{
    socket_.close();
}

void Connection::start()
{
    start_read_header();
}

void Connection::start_read_header()
{
    m_readbuf.resize(header_size);
    boost::asio::async_read(socket_, boost::asio::buffer(m_readbuf),
                            boost::bind(&Connection::handle_read_header, shared_from_this()));
}

void Connection::handle_read_header()
{
    unsigned msg_len = decode_header(m_readbuf);
    std::cout << "MSG LEN: " << msg_len << std::endl;
    start_read_body(msg_len);
}

void Connection::start_read_body(unsigned msg_len)
{
    m_readbuf.resize(header_size + msg_len);
    boost::asio::mutable_buffers_1 buf = boost::asio::buffer(&m_readbuf[header_size], msg_len);
    boost::asio::async_read(socket_, buf, boost::bind(&Connection::handle_read_body, shared_from_this()));
}

void Connection::handle_read_body()
{
    messageFS::Request writeRequest;
    messageFS::Request readed;
    readed.ParseFromArray(&m_readbuf[header_size], m_readbuf.size() - header_size);
    writeRequest.set_name(readed.name());
    switch (readed.id())
    {
    case ServerSyncho::REGISTRATION:
    {
        std::cout << "User has register " << readed.name() << std::endl;
        UserInfo us;
        us.login = readed.name();
        us.password = readed.password();
        postgres_sqldb1->Registration(us);
        writeRequest.set_id(ServerSyncho::OKREG);
        break;
    }
    case ServerSyncho::AUTORIZATION:
    {
        std::string rsdafs = readed.name();
        std::cout << "User tries to autorize " << readed.name() << std::endl;
        UserInfo us1;

        us1.login = readed.name();
        us1.password = readed.password();
        bool isUser = postgres_sqldb1->Login(us1);
        if (isUser)
        {
            std::cout << "User: " << readed.name() << " authorized\n";
            writeRequest.set_id(ServerSyncho::OKLOGIN);
        }
        else
        {
            std::cout << "User: " << readed.name() << " failed to authorize\n";
            writeRequest.set_id(ServerSyncho::BADLOGIN);
        }
        break;
    }
    case 10:
    {
        auto file = FileMeta{
            .fileId = 1,
            .version = 1,
            .fileName = "sgkldfgjflsdh;g",
            .fileExtension = "txt",
            .filePath = "static/",
            .fileSize = 1,
            .chunksCount = 1,
            .isDownload = true,
            .isDeleted = false,
            .isCurrent = true,
            .updateDate = "2020-12-12 0:47:25",
            .createDate = "2020-12-12 0:47:25"};
        std::vector<ChunkMeta> chunksMetaVector;
        for (int i = 0; i < 2; ++i)
        {
            auto chunkMeta = ChunkMeta{.chunkId = i};
            chunksMetaVector.push_back(chunkMeta);
        }

        std::vector<FileChunksMeta> fileChunksMetaVector;
        for (int i = 0; i < 2; ++i)
        {
            auto fileChunkMeta = FileChunksMeta{.chunkId = i, .chunkOrder = i};
            fileChunksMetaVector.push_back(fileChunkMeta);
        }

        auto fileInfo =
            FileInfo{.userId = 3, .file = file, .chunkMeta = chunksMetaVector, .fileChunksMeta = fileChunksMetaVector};

        try
        {
            postgres_sqldb_file->InsertFile(fileInfo);
            auto tt = UserDate{3, "2020-12-19 0:47:25"};
            postgres_sqldb_file->GetUserFilesByTime(tt);
            // postgres_sqldb1.Registration(user);
        }
        catch (PostgresExceptions &exceptions)
        {
            std::cout << exceptions.what() << std::endl;
        }
    }
    default:
        break;
    }

    std::string ans_string;
    writeRequest.SerializePartialToString(&ans_string);
    write(ans_string);
    start_read_header();
    //boost::asio::async_write(socket_, boost::asio::buffer(ans_string, ans_string.size()), boost::bind(&Connection::start_read_header, shared_from_this()));
}
void Connection::write(std::string &msg)
{
    std::vector<boost::uint8_t> buf(4);
    std::string size = encode_header(buf, msg.size());
    msg = size + msg;
    std::cout << "writing" << std::endl;
    boost::asio::write(socket_, boost::asio::buffer(msg));
}
