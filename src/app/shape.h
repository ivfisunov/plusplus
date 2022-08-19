#pragma once

#include "i_shape.h"

#include <iostream>

namespace editor {

class AnyShape : public IShape
{
  public:
    AnyShape(std::string type)
      : m_type(type)
    {
        std::cout << "[Shape] " << type << " added." << std::endl;
    };

    void Render() override
    {
        std::cout << "[Shape] " << GetShapeType() << " rendered." << std::endl;
    }

    std::string GetShapeType() override
    {
        return m_type;
    }

  private:
    std::string m_type;
};

}  // namespace editor
