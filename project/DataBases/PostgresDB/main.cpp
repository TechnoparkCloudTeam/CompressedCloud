#include <iostream>
#include "PostgreSQLDB.h"
#include "MetaDB.h"
#include "UserDB.h"

int main() {
 // MetaDataDB &postgres_sqldb = MetaDataDB::shared("user=lida password=123 dbname=mydb host=127.0.0.1 port=5432");
 // postgres_sqldb.Connect();
  UsersDB &postgres_sqldb1 = UsersDB::shared("user=lida password=123 dbname=mydb host=127.0.0.1 port=5432");
  postgres_sqldb1.Connect();

 try
  {
/*const char* sql=R"(create table if not exists Files (
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
    std::cout << "creating table of Files\n";
    postgres_sqldb.pqExec(sql, PostgresExceptions("can't create table of Files\n"));
*/

    const char* sql1=R"(create table if not exists Users (
       login text,
       password text,
       id serial primary key
       ))";
    std::cout << "creating table of Users\n";
    postgres_sqldb1.pqExec(sql1, PostgresExceptions("can't create table of Users\n"));
  }
  catch (PostgresExceptions &exceptions)
  {
    std::cout << exceptions.what();
  }
 /* auto file = FileMeta
  {
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
      .createDate = "2020-12-12 0:47:25"
  };*/

   auto user = UserInfo{"lida","123"};
    auto user2 = UserInfo{"fill", "123"};


    std::string sql3="select case when '"+user.password+"' =(select password from users where id="+std::to_string(/*user.id*/2)+") then 1 else 0 end";

    std::cout << sql3<<'\n';

/*  std::vector<ChunkMeta> chunksMetaVector;
  for (int i = 0; i < 2; ++i) {
    auto chunkMeta = ChunkMeta{.chunkId = i};
    chunksMetaVector.push_back(chunkMeta);
  }

  std::vector<FileChunksMeta> fileChunksMetaVector;
  for (int i = 0; i < 2; ++i) {
    auto fileChunkMeta = FileChunksMeta{.chunkId = i, .chunkOrder = i};
    fileChunksMetaVector.push_back(fileChunkMeta);
  }

  auto fileInfo =
      FileInfo{.userId = 3, .file = file, .chunkMeta = chunksMetaVector, .fileChunksMeta = fileChunksMetaVector};*/

try
{
        postgres_sqldb1.Registration(user2);

}
 catch (PostgresExceptions &exceptions) {
    std::cout << exceptions.what() << std::endl;
  }



  try {
  /*   postgres_sqldb.InsertFile(fileInfo);
     auto tt = UserDate{3, "2020-12-19 0:47:25"};
	   postgres_sqldb.GetUserFilesByTime(tt);*/
//     postgres_sqldb1.Registration(user);
        std::cout << postgres_sqldb1.isPasswordCorrect(sql3.data(), user, PostgresExceptions("wrong password of user\n"));

  } catch (PostgresExceptions &exceptions) {
    std::cout << exceptions.what() << std::endl;
  }
  return 0;
}

