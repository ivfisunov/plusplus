#pragma once

#include <vector>
#include <string>
#include <chrono>

namespace bulk {

class IObserver
{
  public:
    virtual ~IObserver(){};
    virtual void Update(
        const std::vector<std::pair<std::string, std::chrono::milliseconds>> &commands) = 0;
};

}  // namespace bulk
