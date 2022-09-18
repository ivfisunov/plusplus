#pragma once

#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <chrono>

#include "i_subscriber.h"
#include "i_observer.h"

namespace bulk {

enum class Brackets
{
    Open = 0,
    Close = 1,
};

class Command : public ISubscriber
{
  public:
    Command(int blockSize);

    void Subscribe(IObserver* observer) override;
    void Unsubscribe(IObserver* observer) override;
    void Notify() override;
    void StartProcessing();

  private:
    void ProcessCommand(std::string& cmd);

  private:
    int m_blockSize;
    std::vector<IObserver*> m_observers;
    std::vector<std::pair<std::string, std::chrono::milliseconds>> m_commands;
    int m_cmdCounter{0};
    int m_openBrCounter{0};
    bool m_isDynamicBlock{false};
};

}  // namespace bulk
