#include <iostream>

#include "Cli.hpp"

int main(int argc, char* argv[])
{
    try {
        Cli::HandleArgs(argc, argv);
    } catch (Cli::CliError& err) {
        err.Log();
    }

//    const char* dirPath = "data/docs.gl/";
//    std::vector<std::string> files = Files::ReadDir(dirPath);

//    std::unordered_map<std::string, std::unordered_map<std::string, size_t>> dirIndex;
 //   for (auto &filePath: files) {
  //      Files::IndexFIle(filePath.c_str(), dirIndex[filePath]);
   // }


    //std::cout << "Parsed " << dirIndex.size() << " files" << std::endl;

//    const char *saveToPath = "indexes/index.json";;
 //   Json::DumpToJson(dirIndex, saveToPath); 


}
