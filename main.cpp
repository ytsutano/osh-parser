#include <iostream>
#include <string>
#include <vector>

#include "command.hpp"
#include "parser.hpp"

int main()
{
    std::string input_line;

    for (;;) {
        // Print the prompt.
        std::cout << "osh> " << std::flush;

        // Read a single line.
        if (!std::getline(std::cin, input_line) || input_line == "exit") {
            break;
        }

        try {
            // Parse the input line.
            std::vector<shell_command> shell_commands
                    = parse_command_string(input_line);

            // Print the list of commands.
            std::cout << "-------------------------\n";
            for (const auto& cmd : shell_commands) {
                std::cout << cmd;
                std::cout << "-------------------------\n";
            }
        }
        catch (const std::runtime_error& e) {
            std::cout << "osh: " << e.what() << "\n";
        }
    }

    std::cout << std::endl;
}
