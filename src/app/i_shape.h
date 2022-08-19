#pragma once

#include <string>

namespace editor {

enum class ShapeType {
    Circle,
    Triangle,
    Rectangle,
};

class IShape
{
  public:
    virtual ~IShape() = default;

    virtual void Render() = 0;
    virtual std::string GetShapeType() = 0;
};
}  // namespace editor
