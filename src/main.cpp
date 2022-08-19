#include <memory>
#include "app/app.h"
#include "app/i_shape.h"
#include "app/i_document.h"

int main(int, char**)
{
    editor::App app = editor::App();

    auto& doc = app.NewDocument("doc1", "vec");
    doc->AddShape(editor::ShapeType::Circle);
    doc->AddShape(editor::ShapeType::Rectangle);
    doc->AddShape(editor::ShapeType::Triangle);
    doc->AddShape(editor::ShapeType::Triangle);
    doc->RenderDocument();

    app.ExportDocument(doc);
    app.CloseDocument(doc);
    app.CloseDocument(doc);

    auto& doc2 = app.ImportDocument("doc2", "vec");
    doc2->AddShape(editor::ShapeType::Circle);
    auto& triangle = doc2->AddShape(editor::ShapeType::Triangle);
    doc2->AddShape(editor::ShapeType::Circle);
    doc2->DelShape(triangle);
    app.CloseDocument(doc2);

    return 0;
}
