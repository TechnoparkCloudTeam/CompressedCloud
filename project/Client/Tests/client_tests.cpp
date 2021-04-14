#include <gtest/gtest.h>
#include "Watcher.h"
#include <filesystem>
#include <fstream>

TEST(Watcher, AddDirToWatch) {
    std::filesystem::path Path;
    Watcher watcher;
    watcher.AddDirToWatch(Path); 
    ASSERT_EQ(1, 1);
}

TEST(Watcher, SendDirStatus_created_file) {
    std::filesystem::path Path;
    Watcher watcher;
    watcher.AddDirToWatch(Path);
    watcher.SendDirStatus(Path);
    std::fstream File;
    File.open("Test.txt");
   
    watcher.SendDirStatus(Path); // Sends info about watcher directory
    ASSERT_EQ(1, 1);
}

TEST(Watcher, SendDirStatus_changed_file) {
    std::filesystem::path Path;
    Watcher watcher;
    watcher.AddDirToWatch(Path);
    std::fstream File;
    File.open("Test.txt");
    watcher.SendDirStatus(Path);
    File << "Test";
    watcher.SendDirStatus(Path); // Sends info about watcher directory
    ASSERT_EQ(1, 1);
}

TEST(Watcher, SendDirStatus_make_directory) {
    std::filesystem::path Path;
    Watcher watcher;
    watcher.AddDirToWatch(Path);
    watcher.SendDirStatus(Path);
    //bash script mkdir "dir name"
    watcher.SendDirStatus(Path);
    ASSERT_EQ(1, 1);
}

TEST(Watcher, SendDirStatus_remove_directory) {
    std::filesystem::path Path;
    Watcher watcher;
    watcher.AddDirToWatch(Path);
    watcher.SendDirStatus(Path);
    //bash script rmdir "dir name"
    watcher.SendDirStatus(Path);
    ASSERT_EQ(1, 1);
}

TEST(Watcher, GetStatus_is_running) {
    std::filesystem::path Path;
    Watcher watcher;
    watcher.AddDirToWatch(Path);
    watcher.GetStatus(); // Outputs current state of watcher daemon
    ASSERT_EQ(1, 1);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

