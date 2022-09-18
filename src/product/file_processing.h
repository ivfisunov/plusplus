#pragma once

#include <vector>
#include <iostream>
#include <string>

#include "i_observer.h"
#include "command.h"

namespace bulk {

class FileProcessing : public IObserver
{
  public:
    explicit FileProcessing(Command* command);

    void Update(
        const std::vector<std::pair<std::string, std::chrono::milliseconds>>& commands) override;
    void Save(const std::vector<std::pair<std::string, std::chrono::milliseconds>>& commands);

  private:
    Command* m_command;
};

}  // namespace bulk
