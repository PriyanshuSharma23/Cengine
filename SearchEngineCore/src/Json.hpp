#ifndef JSON_HPP__
#define JSON_HPP__

#include <fstream>
#include <iostream>
#include <json/json.hpp>
#include <string>
#include <unordered_map>

class Json {
  static bool IsValidUTF8(const std::string& str);

 public:
  static void DumpToJson(
      std::unordered_map<std::string, std::unordered_map<std::string, size_t>>&
          dirIndex,
      const char* saveToPath);
};

#endif  // JSON_HPP__
