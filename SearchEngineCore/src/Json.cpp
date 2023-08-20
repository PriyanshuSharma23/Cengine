#include "Json.hpp"

bool Json::IsValidUTF8(const std::string &str)
{
    int i = 0;
    while (i < str.size())
    {
        unsigned char current = str[i];

        // Check for continuation bytes
        if ((current & 0xC0) == 0x80)
        {
            return false;
        }

        // Check for multi-byte characters
        if (current & 0x80)
        {
            int numBytes = 0;
            if ((current & 0xE0) == 0xC0)
            {
                numBytes = 2;
            }
            else if ((current & 0xF0) == 0xE0)
            {
                numBytes = 3;
            }
            else if ((current & 0xF8) == 0xF0)
            {
                numBytes = 4;
            }
            else
            {
                return false;
            }

            for (int j = 1; j < numBytes; ++j)
            {
                if ((i + j) >= str.size() || (str[i + j] & 0xC0) != 0x80)
                {
                    return false;
                }
            }

            i += numBytes;
        }
        else
        {
            ++i;
        }
    }

    return true;
}

void Json::DumpToJson(std::unordered_map<std::string, std::unordered_map<std::string, size_t>> &dirIndex,
                      const char *saveToPath)
{
    nlohmann::json j({});

    for (auto &filePair : dirIndex)
    {
        for (auto &tokenPair : dirIndex[filePair.first])
        {
            if (IsValidUTF8(tokenPair.first))
            {
                j[filePair.first][tokenPair.first] = tokenPair.second;
            }
        }
    }

    std::ofstream outputJson(saveToPath);

    if (outputJson.is_open())
    {
        outputJson << j;
        outputJson.close();
    }
    else
    {
        std::cout << "Unable to open file " << saveToPath << std::endl;
    }
}

std::unordered_map<std::string, std::unordered_map<std::string, size_t>> Json::ExtractFromJson(std::string &content)
{
    nlohmann::json js = nlohmann::json::parse(content);
    std::cout << "Parsed to json" << std::endl;

    return js;
}