
#ifndef INDEXER_HPP
#define INDEXER_HPP

#include <iostream>

#include "Files.hpp"

typedef std::unordered_map<std::string, size_t> TermFreq;
typedef std::unordered_map<std::string, TermFreq> TermIndex;

namespace Indexer
{

void IndexDir(const char *absoluteFilePath);
void IndexFile(const char *filePath, TermFreq &tokenCounts);

TermIndex CreateIndex(const char *dirPath);
TermIndex RetrieveIndex(const char *absoluteFilePath);

class IndexError
{
  private:
    const std::string m_Message;

  public:
    IndexError(const char *message) : m_Message(message)
    {
    }

    IndexError(std::string message) : m_Message(message)
    {
    }

    const std::string GetMessage() const
    {
        return m_Message;
    }
};
} // namespace Indexer

#endif // INDEXER_HPP