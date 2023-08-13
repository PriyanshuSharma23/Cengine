#include <iostream>
#include <fstream>
#include "Files.hpp"

int main()
{
    const char *filePath = "data/docs.gl/el3/abs.xhtml";
    std::cout << Files::ReadFile(filePath);
}
