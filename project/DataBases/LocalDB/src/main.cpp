#include <iostream>
#include "LocalDB.h"
#include <vector>
#include "boost/log/trivial.hpp"
#include <sqlite3.h>



int main(int argc, char **argv) {

UserDB DB("user.dblite");
  {
   User user;
   user.userId = 110;
   user.login = "hhhhhhhhhhhhhhhhhhhhhhhhh";
   user.password = "ggggggggggggggggggggggggggggg";
   user.deviceId = 27;
   user.deviceName = "kdgrtuurufj";
   user.synchFolder = "lrshtgh";
   user.lastUpdate = "vshvgrurjukej";

    DB.addUser(user);
    std::cout << DB.getUserId(user) << std::endl;
    DB.deleteUser(2);
    std::cout << DB.selectUserId();
    std::cout << DB.getDeviceId(user) << std::endl;
    std::cout << DB.getLogin(user) << std::endl;
    std::cout << DB.getPassword(user) << std::endl;
    std::cout << DB.getSynchFolder(user) << std::endl;


    std::cout << DB.selectDeviceId() << std::endl;
    std::cout << DB.selectLogin() << std::endl;
    std::cout << DB.selectPassword(user) << std::endl;
    std::cout << DB.selectFolder() << std::endl;
    std::cout << DB.selectLastUpdate() << std::endl;

    std::cout << DB.isUserExist(2) << std::endl;

    DB.updateSynchFolder(user, "ffffffff");

    std::cout << DB.getSynchFolder(user) << std::endl;

    DB.updatePassword(user, "asdfghjkl");

    std::cout << DB.getPassword(user) << std::endl;

    DB.saveLastUpdate(user);

    std::cout << DB.getLastUpdate(user) << std::endl;

  }

FileDB fileDB("file.dblite");
        
std::cout << fileDB.isFileExist(1) << std::endl;
 {
  FileMeta f;
 // f.fileId = 34;
  f.fileName = "jhflksdl;uw";
  f.fileExtention = "hghgkg";
  f.createDate = "kjhkk";
  f.updateDate = "looo";
  f.isDownload = false;
  f.version = 1;
  f.chunksCount = 0;
  f.filePath = "kjgjhfjhkf";
  f.fileSize = 232;
  fileDB.addFile(f);
  fileDB.updateFile(f);  
}
std::cout << fileDB.selectFileId() << std::endl;

std::cout << fileDB.selectId() << std::endl;

fileDB.deleteFile(10);

fileDB.downloadFile(13);

if(auto file=fileDB.getOneFile(2))
{
        file->printContent();
}
std::cout<<"\n\n";


if(auto list =fileDB.selectAllFiles(); list.size())
{
    for(auto& file:list)
    {
       file.printContent();
       std::cout<<'\n';
    }

}

  return 0;
}
