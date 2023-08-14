
#include <iostream>

namespace Cli {
    void HandleArgs(int argc, char* argv[]);
    void Help();
    void HelpPrompt();

    class CliError {
        private:
            const char* m_Message;

        public:
            CliError(const char* message): m_Message(message) {}
            void Log();
    };
}
