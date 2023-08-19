#include "Files.hpp"

std::string Files::ReadFile(const char *filePath) {
  std::string fileData;
  std::ifstream file(filePath);

  if (file.is_open()) {
    std::string line;
    while (getline(file, line)) {
      fileData += line + "\n";
    }
    file.close();
  } else {
    auto errorMessage = std::string("Unable to open file ") + filePath;
    throw IoError(errorMessage);
  }

  return fileData;
}

std::vector<std::string> Files::ReadDir(const char *dirPath) {
  std::vector<std::string> files;
  DIR *dir = opendir(dirPath);

  if (dir) {
    std::stack<std::string> dirs;
    dirs.push(dirPath);

    while (!dirs.empty()) {
      std::string path = dirs.top();
      dirs.pop();

      struct dirent *ent;
      DIR *dir = opendir(path.c_str());

      while ((ent = readdir(dir)) != NULL) {
        std::string name = ent->d_name;
        if (name == "." || name == "..") {
          continue;
        }

        std::string fullpath = path + "/" + name;
        if (ent->d_type == DT_DIR) {
          dirs.push(fullpath);
        } else {
          files.push_back(fullpath);
        }
      }
      closedir(dir);
    }
  } else {
    auto errorMessage = std::string("Unable to open directory ") + dirPath;
    throw IoError(errorMessage);
  }

  return files;
}

void Files::IndexFIle(const char *filePath,
                      std::unordered_map<std::string, size_t> &tokenCounts) {
  std::string fileContent = Files::ReadFile(filePath);
  std::cout << "Parsing " << filePath << "..." << std::endl;
  try {
    std::string text = XmlParse::GetText(
        (char *)fileContent.data());  // rapidXml requires non-const char *
    Lexer lexer(text.c_str());
    while (!lexer.IsTerminated()) {
      const char *token = lexer.NextToken();
      if (token == nullptr) {
        break;
      }
      int tokenLength = lexer.GetTokenLength(token);
      std::string tokenString(token, tokenLength);
      std::transform(tokenString.begin(), tokenString.end(),
                     tokenString.begin(), ::toupper);

      tokenCounts[tokenString]++;
    }
  } catch (...) {
    std::cout << "Failed to parse " << filePath << std::endl;
  }
}

std::unordered_map<std::string, std::unordered_map<std::string, size_t>>
Files::IndexDir(const char *dirPath) {
  try {
    std::vector<std::string> files = Files::ReadDir(dirPath);
    std::unordered_map<std::string, std::unordered_map<std::string, size_t>>
        dirIndex;
    for (auto &filePath : files) {
      Files::IndexFIle(filePath.c_str(), dirIndex[filePath]);
    }

    std::cout << "Parsed " << dirIndex.size() << " files" << std::endl;
    return dirIndex;
  } catch (Files::IoError &error) {
    throw;
  }
}
