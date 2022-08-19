#pragma once

#include <string>
#include <memory>

#include "shape.h"
#include "i_shape.h"

namespace editor {

class IDocument
{
  public:
    ~IDocument() = default;

    virtual const std::unique_ptr<IShape>& AddShape(ShapeType type) = 0;
    virtual void DelShape(const std::unique_ptr<IShape>& shape) = 0;

    virtual void RenderDocument() = 0;
    virtual std::string GetDocName() = 0;
};

}  // namespace editor
