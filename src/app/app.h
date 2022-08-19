#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <unordered_set>

#include "i_document.h"
#include "document.h"

namespace editor {

class App
{
  public:
    const std::unique_ptr<IDocument>& NewDocument(std::string docName, std::string docType)
    {
        std::cout << "[APP] New document " << docName << " created." << std::endl;
        auto doc = std::make_unique<Document>(docName, docType);
        auto [it, is_inserted] = m_documents.insert(std::move(doc));
        return *it;
    }

    bool CloseDocument(const std::unique_ptr<IDocument>& doc)
    {
        if (m_documents.count(doc)) {
            std::cout << "[APP] Document \"" << doc->GetDocName() << "\" closed." << std::endl;
            m_documents.erase(doc);
            return true;
        }
        return false;
    }

    const std::unique_ptr<IDocument>& ImportDocument(std::string docName, std::string docType)
    {
        std::cout << "[APP] Import document " << docName << "." << std::endl;
        auto doc = std::make_unique<Document>(docName, docType);
        auto [it, is_inserted] = m_documents.insert(std::move(doc));
        return *it;
    }

    bool ExportDocument(const std::unique_ptr<IDocument>& doc)
    {
        auto it = m_documents.find(doc);
        if (it != m_documents.end()) {
            std::cout << "[APP] Export document " << (*it)->GetDocName() << std::endl;
            return true;
        }
        return false;
    }

  private:
    std::unordered_set<std::unique_ptr<IDocument>> m_documents{};
};

}  // namespace editor
