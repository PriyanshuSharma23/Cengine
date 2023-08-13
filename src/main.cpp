#include <iostream>
#include <fstream>
#include "Files.hpp"

int main()
{
    std::vector<std::string> files = Files::ReadDir("data/docs.gl");
    std::cout << "Number of files: " << files.size() << "\n";
}
