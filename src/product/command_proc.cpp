#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>

#include "command_proc.h"
#include "i_subscriber.h"
#include "i_observer.h"

namespace bulk {

std::string BracketsToString(Brackets br)
{
    switch (br) {
        case Brackets::Open:
            return "{";
        case Brackets::Close:
            return "}";
        default:
            return "";
    }
}

Command::Command(int blockSize)
  : m_blockSize(blockSize){};

void Command::Subscribe(IObserver* observer)
{
    m_observers.push_back(observer);
}

void Command::Unsubscribe(IObserver* observer)
{
    m_observers.erase(std::remove(m_observers.begin(), m_observers.end(), observer));
}

void Command::Notify()
{
    for (const auto& observer : m_observers) {
        observer->Update(m_commands);
    }
}

void Command::StartProcessing()
{
    std::string cmd;
    while (std::getline(std::cin >> std::ws, cmd)) {
        ProcessCommand(cmd);
    }
}

void Command::ProcessCommand(std::string& cmd)
{
    if (cmd == BracketsToString(Brackets::Open)) {
        m_openBrCounter++;
        if (m_openBrCounter == 1) {
            m_isDynamicBlock = true;
            Notify();
            m_commands.clear();
        }
        return;
    } else if (cmd == BracketsToString(Brackets::Close)) {
        m_openBrCounter--;
        if (m_openBrCounter == 0) {
            m_isDynamicBlock = false;
            m_cmdCounter = 0;
            Notify();
            m_commands.clear();
        }
        return;
    }

    m_commands.push_back(
        {cmd,
         std::chrono::duration_cast<std::chrono::milliseconds>(
             std::chrono::system_clock::now().time_since_epoch())});

    if (!m_isDynamicBlock) {
        m_cmdCounter++;
        if (m_cmdCounter == m_blockSize) {
            Notify();
            m_commands.clear();
            m_cmdCounter = 0;
        }
    }
}

}  // namespace bulk
