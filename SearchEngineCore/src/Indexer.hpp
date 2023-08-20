
#ifndef INDEXER_HPP
#define INDEXER_HPP

#include <iostream>

#include "Files.hpp"

namespace Indexer {
void IndexDir(const char* absoluteFilePath);
void IndexFile(const char* filePath,
               std::unordered_map<std::string, size_t>& tokenCounts);

std::unordered_map<std::string, std::unordered_map<std::string, size_t>>
CreateIndex(const char* dirPath);

void RetrieveIndex(const char* absoluteFilePath);

}  // namespace Indexer

#endif  // INDEXER_HPP