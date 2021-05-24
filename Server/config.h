#pragma once
enum ServerSyncho : int
{
    OKREG = 0,
    BAD = 1,
    REGISTRATION = 2,
    OKLOGIN = 3,
    BADLOGIN = 4,
    AUTORIZATION = 5,
    ADDFILE = 6,
};

enum ServerFS : int
{
    CREATEFOLDER = 1,
    DELETEFILE = 2,
    SENDFILE = 3,
    DOWNLOADFILE = 4,
    OKSENDING = 5,
    OKDOWNLOAD = 6,
};
