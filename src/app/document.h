#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <unordered_set>

#include "i_document.h"
#include "i_shape.h"
#include "shape.h"

namespace editor {

class Document : public IDocument
{
  public:
    Document(std::string docName, std::string docType)
      : m_docName(docName)
      , m_docType(docType){};

    const std::unique_ptr<IShape>& AddShape(ShapeType type) override
    {
        static std::unique_ptr<IShape> empty;
        switch (type) {
            case ShapeType::Circle: {
                // auto shape = std::make_unique<Shape>("Circle");
                auto [it, is_inserted] = m_shapes.emplace(std::make_unique<AnyShape>("Circle"));
                return *it;
            }
            case ShapeType::Rectangle: {
                // auto shape = std::make_unique<Shape>("Rectangle");
                auto [it, is_inserted] = m_shapes.emplace(std::make_unique<AnyShape>("Rectangle"));
                return *it;
            }
            case ShapeType::Triangle: {
                // auto shape = std::make_unique<Shape>("Triangle");
                auto [it, is_inserted] = m_shapes.emplace(std::make_unique<AnyShape>("Triangle"));
                return *it;
            }
            default:
                return empty;
        }
    };
    void DelShape(const std::unique_ptr<IShape>& shape) override
    {
        std::cout << "[Document] Shape " << shape->GetShapeType() << " deleted." << std::endl;
        m_shapes.erase(shape);
    };

    void RenderDocument() override
    {
        std::cout << "[Document] Rendeting full document." << std::endl;
        for (const auto& shape : m_shapes) {
            shape->Render();
        }
    };

    std::string GetDocName()
    {
        return m_docName;
    }

  private:
    std::string m_docName{};
    std::string m_docType{};
    std::unordered_set<std::unique_ptr<IShape>> m_shapes{};
};

}  // namespace editor
