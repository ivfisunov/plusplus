#pragma once

#include <vector>
#include <iostream>
#include <string>

#include "i_observer.h"
#include "command_proc.h"

namespace bulk {

class ConsoleProcessing : public IObserver
{
  public:
    explicit ConsoleProcessing(Command* command);

    void Update(
        const std::vector<std::pair<std::string, std::chrono::milliseconds>>& commands) override;
    void Render(const std::vector<std::pair<std::string, std::chrono::milliseconds>>& commands);

  private:
    Command* m_command;
};

}  // namespace bulk
