#include <iostream>
#include "Files.hpp"
#include "Tokenizer.hpp"

int main()
{
    // std::vector<std::string> files = Files::ReadDir("data/docs.gl");
    // std::cout << "Number of files: " << files.size() << "\n";

    // for (auto &file : files)
    // {
    //     std::cout << file << " " << Files::ReadFile(file.c_str()).size() << " chars\n";
    // }
    // const char *filePath = "data/docs.gl/el3/abs.xhtml";
    // std::string fileContent = Files::ReadFile(filePath);
    // std::string fileContent = R"(
    //     <td style="text-align: left; border-right: 2px solid ; ">abs (genIType)</td>
    //     <td style=\"text-align: center; border-right: 2px solid ; \">-</td>)";

    // Tokenizer tokenizer(fileContent);

    // while (tokenizer.HasNextToken())
    // {
    //     auto nextToken = tokenizer.NextToken();
    //     size_t len = tokenizer.GetToken() - nextToken;
    //     std::string token(nextToken, len);
    //     std::cout << token << "\t";
    // }
}
