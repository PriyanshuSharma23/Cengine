#include <cstdlib>
#include <iostream>

#include "Cli.hpp"

int main(int argc, char *argv[])
{
    try
    {
        Cli::HandleArgs(argc, argv);
    }
    catch (Cli::CliError &err)
    {
        err.Log();
    }
}
