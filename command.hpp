/*
 * Copyright (c) 2018, Yutaka Tsutano
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <string>
#include <vector>

enum class istream_mode { term, file, pipe };
enum class ostream_mode { term, file, append, pipe };
enum class next_command_mode { any, success, fail };

struct shell_command {
    std::string cmd;
    std::vector<std::string> args;

    istream_mode cin_mode = istream_mode::term;
    std::string cin_file;

    ostream_mode cout_mode = ostream_mode::term;
    std::string cout_file;

    next_command_mode next_mode = next_command_mode::any;
};

inline std::ostream& operator<<(std::ostream& os, const istream_mode& x)
{
    const char* text[] = {"term", "file", "pipe"};
    return os << text[static_cast<size_t>(x)];
}

inline std::ostream& operator<<(std::ostream& os, const ostream_mode& x)
{
    const char* text[] = {"term", "file", "append", "pipe"};
    return os << text[static_cast<size_t>(x)];
}

inline std::ostream& operator<<(std::ostream& os, const next_command_mode& x)
{
    const char* text[] = {"any", "success", "fail"};
    return os << text[static_cast<size_t>(x)];
}

inline std::ostream& operator<<(std::ostream& os, const shell_command& x)
{
    os << "cmd: " << x.cmd << "\n";
    for (const auto& arg : x.args) {
        os << "arg: " << arg << "\n";
    }
    os << "cin_file: " << x.cin_file << "\n";
    os << "cin_mode: " << x.cin_mode << "\n";
    os << "cout_file: " << x.cout_file << "\n";
    os << "cout_mode: " << x.cout_mode << "\n";
    os << "next_mode: " << x.next_mode << "\n";
    return os;
}

#endif
