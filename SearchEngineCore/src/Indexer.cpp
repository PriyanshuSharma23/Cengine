#include "Indexer.hpp"

static inline size_t Encode(const char *str)
{
    return std::hash<std::string>{}(str);
}

void Indexer::IndexDir(const char *absoluteDirPath)
{
    try
    {
        auto dirIndex = CreateIndex(absoluteDirPath);
        size_t hashedFilePath = Encode(absoluteDirPath);

        std::string saveToPath = "SearchEngineCore/indexes/";
        saveToPath += std::to_string(hashedFilePath) + ".json";

        std::cout << "Saving index to " << saveToPath << std::endl;

        Json::DumpToJson(dirIndex, saveToPath.c_str());
    }
    catch (Files::IoError &err)
    {
        std::cerr << err.GetMessage() << std::endl;
    }
}

TermIndex Indexer::RetrieveIndex(const char *absoluteDirPath)
{
    std::string content;
    try
    {
        std::string hashedPath =
            std::string("SearchEngineCore/indexes/") + std::to_string(Encode(absoluteDirPath)) + ".json";
        content = Files::ReadFile(hashedPath.c_str());

        auto parsedJson = Json::ExtractFromJson(content);
        return parsedJson;
    }
    catch (Files::IoError &err)
    {
        std::cout << err.GetMessage() << std::endl;
        throw IndexError(std::string("Failed to index ") + absoluteDirPath);
    }
}

TermIndex Indexer::CreateIndex(const char *dirPath)
{
    try
    {
        std::vector<std::string> files = Files::ReadDir(dirPath);
        TermIndex dirIndex;
        for (auto &filePath : files)
        {
            IndexFile(filePath.c_str(), dirIndex[filePath]);
        }

        std::cout << "Parsed " << dirIndex.size() << " files" << std::endl;
        return dirIndex;
    }
    catch (Files::IoError &error)
    {
        std::cout << error.GetMessage() << std::endl;
        throw IndexError(std::string("Failed to create index for ") + dirPath);
    }
}

void Indexer::IndexFile(const char *filePath, TermFreq &tokenCounts)
{
    std::string fileContent = Files::ReadFile(filePath);
    std::cout << "Parsing " << filePath << "..." << std::endl;
    try
    {
        std::string text = XmlParse::GetText((char *)fileContent.data()); // rapidXml requires non-const char *
        Lexer lexer(text.c_str());
        while (!lexer.IsTerminated())
        {
            const char *token = lexer.NextToken();
            if (token == nullptr)
            {
                break;
            }
            int tokenLength = lexer.GetTokenLength(token);
            std::string tokenString(token, tokenLength);
            std::transform(tokenString.begin(), tokenString.end(), tokenString.begin(), ::toupper);

            tokenCounts[tokenString]++;
        }
    }
    catch (...)
    {
        std::cout << "Failed to parse " << filePath << std::endl;
    }
}
