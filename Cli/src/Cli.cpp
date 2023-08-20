#include "Cli.hpp"

const char* AbsolutePath(const char* relPath) {
  return realpath(relPath, nullptr);
}

void Cli::Help() {
  std::cout << "Cengine (C++ Search Engine)" << std::endl;
  std::cout << "Commands: " << std::endl;
  std::cout << "\t" << 1 << ") "
            << "help  - Get a list of all commands" << std::endl;
  std::cout << "\t" << 2 << ") "
            << "index - Index all the XML/XHTML files in a directory"
            << std::endl;
}

void Cli::HelpPrompt() {
  std::cout << "\n"
            << "Use the help command for more information" << std::endl;
}

void Cli::HandleArgs(int argc, char* argv[]) {
  using namespace Cli;

  if (argc < 2) {  // No argument passed
    throw CliError("No arguments are passed");
  }

  std::string cmd = argv[1];

  if (cmd == "help") {
    Help();
  } else if (cmd == "index") {
    if (argc < 3) {
      throw CliError("Please enter a directory path to index.");
    }

    const char* dirPath = argv[2];
    const char* absolutePath = AbsolutePath(dirPath);

    if (!absolutePath) {
      throw CliError("Invalid path");
    }

    Indexer::IndexDir(absolutePath);
  }
}

void Cli::CliError::Log() {
  std::cout << m_Message << std::endl;
  Cli::HelpPrompt();
}
