#include <iostream>
#include "Files.hpp"
#include "Lexer.hpp"
#include "XmlParse.hpp"

int main()
{
    const char *filePath = "data/docs.gl/el3/acos.xhtml";
    std::string fileContent = Files::ReadFile(filePath);
    std::string text = XmlParse::GetText((char *)fileContent.data()); // rapidXml requires non-const char *

    std::cout << text << "\n";

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
        std::cout << tokenString << "\n";
    }
}
