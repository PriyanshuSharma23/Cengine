#ifndef FILES_HPP
#define FILES_HPP

#include <string>
#include <fstream>
#include <dirent.h>
#include <vector>
#include <stack>
#include <unordered_map>
#include <iostream>

#include "Json.hpp"
#include "Lexer.hpp"
#include "XmlParse.hpp"

namespace Files
{
    std::string ReadFile(const char *filePath);

    /*
     * ReadDir (const char* dirPath);
     * dirPath - Path of the directory to be read.
     * 
     * returns - Vector of all the files inside a given directory (Including subfolders)
     * throws - IoError, when unable to open the given dir
     */
    std::vector<std::string> ReadDir(const char *dirPath);

    void IndexFIle(const char* filePath, std::unordered_map<std::string, size_t>& tokenCounts);

    std::unordered_map<std::string, std::unordered_map<std::string, size_t>> IndexDir(const char* dirPath);


    class IoError {
        private:
        const char* m_Messge;
        public:
        IoError(const char* message): m_Messge(message) {}
        const char* GetMessage() const { return m_Messge; }
    };

}

#endif // FILES_HPP
