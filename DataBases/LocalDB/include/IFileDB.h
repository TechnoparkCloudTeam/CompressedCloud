#pragma once

#include "FileDB.h"

#include <functional>

struct IFileDB
{
    virtual bool exec(const std::string_view sql,
              std::function<int(const s_record &r, void *context)> record_callback = nullptr //retuen false to continue enumeration
              ,
              void *context = nullptr) = 0;

    virtual bool connect(const std::string_view fileNameDB) = 0;
    
    virtual void disconnect() = 0;
    
    virtual void createTable() = 0;

    virtual void addFile(FileMeta &file) = 0;
    
    virtual void deleteFile(const std::string &fileName, const std::string &filePath) = 0;
    
    virtual void downloadFile(const int &fileId) = 0;

    virtual bool isFileExist(const int &fileId) = 0;

    virtual std::optional<FileMeta> getOneFile(const int id) = 0;

    virtual int selectId() = 0;
    
    virtual int selectFileId() = 0;
    
/*     virtual FileMeta selectFile(const int &fileId) = 0;
 */    
    virtual std::vector<FileMeta> selectAllFiles() = 0;

    virtual void updateFile(FileMeta &file) = 0;
};
