#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <fstream>

#include "file_processing.h"

namespace bulk {

FileProcessing::FileProcessing(Command* command)
  : m_command(command)
{
    m_command->Subscribe(this);
}

void FileProcessing::Update(
    const std::vector<std::pair<std::string, std::chrono::milliseconds>>& commands)
{
    if (!commands.empty()) {
        Save(commands);
    }
}

void FileProcessing::Save(
    const std::vector<std::pair<std::string, std::chrono::milliseconds>>& commands)
{
    const auto [cmd, timeStamp] = commands[0];

    std::ofstream file;
    file.open("bulk" + std::to_string(timeStamp.count()) + ".log", std::ios::out | std::ios::trunc);
    if (file) {
        for (auto it = commands.begin(); it != commands.end(); ++it) {
            auto [cmd, timeStamp] = *it;
            file << cmd;
            if (it != --commands.end()) {
                file << ", ";
            }
        }
        file << std::endl;
        file.close();
    }
}

}  // namespace bulk
