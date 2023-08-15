#include <iostream>
#include <cstdlib>

#include "Files.hpp"
#include "Json.hpp"
#include "Cli.hpp"

int main(int argc, char* argv[])
{
    try {
        Cli::HandleArgs(argc, argv);
    }catch (Cli::CliError& err) {
        err.Log();
    }


}
