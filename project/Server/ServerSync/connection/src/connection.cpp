#include <iostream>
#include "connection.h"
#include "PostgreSQLDB.h"
#include "../../../DataBases/PostgresDB/UserDB/include/UserDB.h"
#include "../../../DataBases/PostgresDB/MetaDB/include/MetaDB.h"
#include "../../../DataBases/PostgresDB/UserDB/include/UserInfo.h"
#include "../../../DataBases/PostgresDB/MetaDB/include/FileInfo.h"
enum ServerSyncho
{
    OK = 0,
    REGISTRATION = 1,
    AUTORIZATION = 2,
    EXERTFILE = 3,
};

Connection::Connection(boost::asio::ip::tcp::socket socket_) : socket_(std::move(socket_))
{
}

void Connection::stop()
{
    socket_.close();
}

void Connection::start()
{
    socket_.async_read_some(boost::asio::buffer(data_),
                            boost::bind(&Connection::read, shared_from_this()));
}
void Connection::read()
{
    messageFS::Request writeRequest;
    messageFS::Request readRequest;

    readRequest.ParseFromString(data_);
    std::cout << readRequest.id() << " " << readRequest.name() << std::endl;

    switch (readRequest.id())
    {
    case ServerSyncho::REGISTRATION:
    {
        std::cout << "User has register " << readRequest.name() << std::endl;
        UsersDB &postgres_sqldb1 = UsersDB::shared("user=lida password=123 dbname=mydb host=127.0.0.1 port=5432");
        postgres_sqldb1.Connect();

        const char *sql1 = R"(create table if not exists Users (
       login text,
       password text,
       id integer
       ))";
        std::cout << "creating table of Users\n";
        postgres_sqldb1.pqExec(sql1, PostgresExceptions("can't create table of Users\n"));
        UserInfo us;
        us.login = "sdgfsdgldf";
        us.password = "dfgsg";
        postgres_sqldb1.Registration(us);
        writeRequest.set_id(ServerSyncho::OK);
        break;
    }
    case ServerSyncho::EXERTFILE:
    {
        std::cout << "User added file " << readRequest.name() << std::endl;
        MetaDataDB &postgres_sqldb = MetaDataDB::shared("user=lida password=123 dbname=mydb host=127.0.0.1 port=5432");
        postgres_sqldb.Connect();
        const char *sql = R"(create table if not exists Files (
       fileId integer,
       userId integer,
       version integer,
       fileName text,
       fileExtention text,
       filePath text,
       fileSize integer,
       chunksCount integer,
       isDownload boolean,
       isDeleted boolean,
       isCurrent boolean,
       updateDate timestamp,
       createDate timestamp
))";
        auto file = FileMeta{
            .fileId = 1,
            .version = 1,
            .fileName = "test",
            .fileExtension = "txt",
            .filePath = "static/",
            .fileSize = 1,
            .chunksCount = 1,
            .isDownload = true,
            .isDeleted = false,
            .isCurrent = true,
            .updateDate = "2020-12-12 0:47:25",
            .createDate = "2020-12-12 0:47:25"};
        std::cout << "creating table of Files\n";
        postgres_sqldb.pqExec(sql, PostgresExceptions("can't create table of Files\n"));
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

        postgres_sqldb.InsertFile(fileInfo);
        auto tt = UserDate{3, "2020-12-19 0:47:25"};
        postgres_sqldb.GetUserFilesByTime(tt);
    }
    default:
        break;

        std::string ans_string;
        writeRequest.SerializePartialToString(&ans_string);
        boost::asio::async_write(socket_, boost::asio::buffer(ans_string, 100), boost::bind(&Connection::write, shared_from_this()));
    }
}
void Connection::write()
{
    std::cout << "writing" << std::endl;
    socket_.async_read_some(boost::asio::buffer(data_),
                            boost::bind(&Connection::read, shared_from_this()));
}
