#ifndef FILES_HPP
#define FILES_HPP

#include <string>
#include <fstream>
#include <dirent.h>
#include <vector>
#include <stack>
#include <unordered_map>
#include <iostream>
#include "Lexer.hpp"
#include "XmlParse.hpp"

namespace Files
{
    std::string ReadFile(const char *filePath);
    std::vector<std::string> ReadDir(const char *dirPath);
    void IndexFIle(const char* filePath, std::unordered_map<std::string, size_t>& tokenCounts);
}

#endif // FILES_HPP
