#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>
#include <string>
#include <stdexcept>

#include "command.hpp"

struct parsing_error : public std::runtime_error {
    using runtime_error::runtime_error;
};

std::vector<shell_command> parse_command_string(const std::string& str);

#endif
