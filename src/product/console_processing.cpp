#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
#include <iostream>

#include "console_processing.h"

namespace bulk {

ConsoleProcessing::ConsoleProcessing(Command* command)
  : m_command(command)
{
    m_command->Subscribe(this);
}

void ConsoleProcessing::Update(
    const std::vector<std::pair<std::string, std::chrono::milliseconds>>& commands)
{
    if (!commands.empty()) {
        Render(commands);
    }
}

void ConsoleProcessing::Render(
    const std::vector<std::pair<std::string, std::chrono::milliseconds>>& commands)
{
    std::cout << "bulk: ";
    for (auto it = commands.begin(); it != commands.end(); ++it) {
        auto [cmd, timeStamp] = *it;
        std::cout << cmd;
        if (it != --commands.end()) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

}  // namespace bulk
