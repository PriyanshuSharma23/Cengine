#include "Files.hpp"

std::string Files::ReadFile(const char *filePath) {
  std::string fileData;
  std::ifstream file(filePath);

  if (!file.good()) {
    auto errorMessage = std::string("Unable to open file ") + filePath;
    throw IoError(errorMessage);
  }

  if (file.is_open()) {
    std::string line;
    while (getline(file, line)) {
      fileData += line + "\n";
    }
    file.close();
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
    std::string errorMessage =
        std::string("Unable to open directory ") + dirPath;
    throw IoError(errorMessage);
  }

  return files;
}
