#include <vector>
#include <memory>
#include <string>
#include <ctime>

struct s_record;
struct FileMeta {
  int fileId{};
  int version{};
  std::string fileName;
  std::string fileExtention;
  std::string filePath;
  int fileSize{};
  int chunksCount{};
  bool isDownload{};
  bool isDeleted{};
  bool isCurrent{};
  std::string updateDate;
  std::string createDate;

  std::string GetFilePath() const {
    return filePath + '/' + fileName + fileExtention;
  }
  void fillMeFromRecord(const s_record& r);
  void printContent() const;
};

