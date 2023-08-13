#include <iostream>
#include "Files.hpp"
#include "Tokenizer.hpp"
#include "XmlParse.hpp"

int main()
{
    const char *filePath = "data/docs.gl/el3/acos.xhtml";
    std::string fileContent = Files::ReadFile(filePath);
    std::string text = XmlParse::GetText((char *)fileContent.data());

    std::cout << text << "\n";
}
