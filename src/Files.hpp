#ifndef FILES_HPP
#define FILES_HPP

#include <string>
#include <fstream>
#include <dirent.h>
#include <vector>
#include <stack>
#include <iostream>

namespace Files
{
    std::string ReadFile(const char *filePath);
    std::vector<std::string> ReadDir(const char *dirPath);
}

#endif // FILES_HPP
