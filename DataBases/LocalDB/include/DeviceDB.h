#pragma once
#include <memory>
#include "LocalDB.h"

class DeviceDB {
public:
        int getDeviceId();
        int selectDeviceId();
private:
        int id;
        std::string synchFolder;
        std::shared_ptr<LocalDB> localDB;
};
