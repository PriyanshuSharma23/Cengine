
#include <cstdlib>
#include <functional>
#include <iostream>
#include <string>

#include "Files.hpp"
#include "Json.hpp"

namespace Cli {
void HandleArgs(int argc, char* argv[]);
void Help();
void HelpPrompt();

class CliError {
 private:
  const char* m_Message;

 public:
  CliError(const char* message) : m_Message(message) {}
  void Log();
};
}  // namespace Cli
