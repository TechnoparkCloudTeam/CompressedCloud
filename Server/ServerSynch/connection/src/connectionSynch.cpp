#include "connectionSynch.h"

Connection::Connection(boost::asio::ip::tcp::socket socket_, std::shared_ptr<UsersDB> postgres_sqldb12,
                       std::shared_ptr<MetaDataDB> postgres_sqldb_file, std::shared_ptr<FriendDB> postgres_sqldb_friend)
    : socket_(std::move(socket_)),
      postgres_sqldb1(postgres_sqldb12),
      postgres_sqldb_file(postgres_sqldb_file),
      postgres_sqldb_friends(postgres_sqldb_friend)
{
}

void Connection::stop()
{
    socket_.close();
}

void Connection::start()
{
    startReadHeader();
}

void Connection::startReadHeader()
{
    m_readbuf.resize(header_size);
    boost::asio::async_read(socket_, boost::asio::buffer(m_readbuf),
                            boost::bind(&Connection::handleReadHeader, shared_from_this()));
}

void Connection::handleReadHeader()
{
    unsigned msg_len = headerMenager.decodeHeader(m_readbuf);
    std::cout << "MSG LEN: " << msg_len << std::endl;
    startReadBody(msg_len);
}

void Connection::startReadBody(unsigned msg_len)
{
    m_readbuf.resize(header_size + msg_len);
    boost::asio::mutable_buffers_1 buf = boost::asio::buffer(&m_readbuf[header_size], msg_len);
    boost::asio::async_read(socket_, buf, boost::bind(&Connection::handleReadBody, shared_from_this()));
}

void Connection::handleReadBody()
{
    messageFS::Request writeRequest;
    messageFS::Request readed;
    readed.ParseFromArray(&m_readbuf[header_size], m_readbuf.size() - header_size);
    writeRequest.set_name(readed.name());
    //readed.PrintDebugString();
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
    case ServerSyncho::ADDFILE:
    {
        std::cout<<"addfiel";
        readed.PrintDebugString();
        auto file = FileMeta{
            .version = 1,
            .fileName = readed.filename(),
            .fileExtension = readed.fileextention(),
            .filePath = readed.filepath(),
            .fileSize = readed.filesize(),
            .chunksCount = 1,
            .isDownload = true,
            .isDeleted = false,
            .isCurrent = true,
            .updateDate = "2020-12-12 0:47:25",
            .createDate = "2020-12-12 0:47:25"};
        //TODO:: че то куда то это деть
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
            FileInfo{.userId = postgres_sqldb1->getUserIdFromLogin(readed.name()),
                     .file = file,
                     .chunkMeta = chunksMetaVector,
                     .fileChunksMeta = fileChunksMetaVector};
        std::cout <<"\n\n\n UserID:: "<<fileInfo.userId<<"\n\n\n";
        try
        {
            postgres_sqldb_file->InsertFile(fileInfo);
            
            // auto tt = UserDate{readed.nameid(), "2020-12-19 0:47:25"};
            //postgres_sqldb_file->GetUserFilesByTime(tt);
            // postgres_sqldb1.Registration(user);
        }
        catch (PostgresExceptions &exceptions)
        {
            std::cout << exceptions.what() << std::endl;
        }
        writeRequest.set_id(ServerSyncho::OKSEND);
        break;
    }
    case ServerSyncho::ADDFRIEND:
    {
        std::cout << "Friend " << readed.name() << " added to friend: " << readed.loginfriend() << "\n";
        postgres_sqldb_friends->AddFriend(postgres_sqldb1->getUserIdFromLogin(readed.name()),
                                          postgres_sqldb1->getUserIdFromLogin(readed.loginfriend()));
        if (postgres_sqldb_friends->CheckFriendship(postgres_sqldb1->getUserIdFromLogin(readed.name()),
                                                    postgres_sqldb1->getUserIdFromLogin(readed.loginfriend())))
        {
            std::cout << readed.name() + " is friend with " + readed.loginfriend() << "\n";
            writeRequest.set_id(ServerSyncho::FRIENDSHIPSUCCESSFUL);
        }
        else
        {
            std::cout << readed.name() + " is not friend with " + readed.loginfriend() << "\n";
            writeRequest.set_id(ServerSyncho::WAITINGFRIENDSHIP);
        }
        break;
    }
    case ServerSyncho::CHECKFRIENDANDFILE:
    {
        readed.PrintDebugString();
        //TODO:: добавить также проверку на то, что у этого друга есть вообще этот файл
        if (postgres_sqldb_friends->CheckFriendship(postgres_sqldb1->getUserIdFromLogin(readed.name()),
                                                    postgres_sqldb1->getUserIdFromLogin(readed.loginfriend())))
        {
            writeRequest.set_id(ServerSyncho::CHECKFRIENDANDFILESUCCESSFUL);
            writeRequest.set_loginfriend(readed.loginfriend());
            writeRequest.set_filename(readed.filename());
            writeRequest.set_name(readed.name());
        }
        else
        {
            writeRequest.set_id(ServerSyncho::CHECKFRIENDANDFILEBAD);
            writeRequest.set_loginfriend(readed.loginfriend());
            writeRequest.set_filename(readed.filename());

        }
        break;
    }
    case ServerSyncho::DELETEFILES: 
    {
        std::cout<<"deleted file";
        postgres_sqldb_file->deleteFile(readed.name(), readed.filename());
        writeRequest.set_id(ServerSyncho::OKDELETES);
        break;   
    }
    default:
        break;
    }

    std::string ans_string;
    writeRequest.SerializePartialToString(&ans_string);
    write(ans_string);
    startReadHeader();
}
void Connection::write(std::string &msg)
{
    std::vector<boost::uint8_t> buf(4);
    std::string size = headerMenager.encodeHeader(buf, msg.size());
    msg = size + msg;
    std::cout << "writing" << std::endl;
    boost::asio::write(socket_, boost::asio::buffer(msg));
}
