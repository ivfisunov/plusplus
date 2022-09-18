#pragma once

#include <vector>
#include <string>
#include <memory>

#include "i_observer.h"

namespace bulk {

class ISubscriber
{
  public:
    virtual ~ISubscriber() = default;
    virtual void Subscribe(IObserver* observer) = 0;
    virtual void Unsubscribe(IObserver* observer) = 0;
    virtual void Notify() = 0;
};

}  // namespace bulk
