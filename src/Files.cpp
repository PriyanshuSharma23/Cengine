#include "Files.hpp"

std::string Files::ReadFile(const char *filePath)
{
    std::string fileData;
    std::ifstream file(filePath);

    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            fileData += line + "\n";
        }
        file.close();
    }
    else
    {
        std::cout << "Unable to open file";
    }

    return fileData;
}
