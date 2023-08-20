#ifndef FILES_HPP
#define FILES_HPP

#include <dirent.h>

#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "Json.hpp"
#include "Lexer.hpp"
#include "XmlParse.hpp"

namespace Files {
/**
 * ReadFile (const char* filePath)
 * filePath - Path of the file to be read
 *
 * returns - std::string of the content in the file
 * throws - `IoError` when unable to read the given file
 */
std::string ReadFile(const char* filePath);

/*
 * ReadDir (const char* dirPath);
 * dirPath - Path of the directory to be read.
 *
 * returns - Vector of all the files inside a given directory (Including
 * subfolders) throws - IoError, when unable to open the given dir
 */
std::vector<std::string> ReadDir(const char* dirPath);



class IoError {
 private:
  const char* m_Messge;

 public:
  IoError(std::string& message) : m_Messge(message.c_str()) {}
  IoError(const char* message) : m_Messge(message) {}
  const char* GetMessage() const { return m_Messge; }
};

}  // namespace Files

#endif  // FILES_HPP
