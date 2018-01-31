# Alternative Parser for `osh`

PA1 comes with ugly broken parser. This is an alternative implementation you
can use.

Just mention you've used this library by Yutaka Tsutano instead in your
README.txt.

## 1 Usage

Read [main.cpp](main.cpp) (usage) and [command.hpp](command.hpp) (data
structure).

### 1.1 Compiling & Running on CSE

You can run the following four commands to compile and run on cse.unl.edu:

```sh
git clone https://github.com/ytsutano/osh-parser.git
cd osh-parser
make
./osh
```

### 1.2 Parsing

`parse_command_string()` returns a vector of parsed commands (defined in
[command.hpp](command.hpp)) from a line of text input from the terminal.

```cpp
// 1. Get a line from the terminal.
std::string input_line = "echo hello world | sort | uniq > test.txt";

// 2. Parse.
std::vector<shell_command> shell_commands = parse_command_string(input_line);
```

This is basically all you need to do for parsing. You just need to execute the
commands listed in `shell_commands` vector to implement the assignment.

### 1.3 Printing the Parsed Commands

It is helpful to print the parsed commands when implementing the execution part
of the shell. You can do so with the following code:

```cpp
std::cout << "-------------------------\n";
for (const auto& cmd : shell_commands) {
    std::cout << cmd;
    std::cout << "-------------------------\n";
}
```

The result of parsing `echo hello world | sort | uniq > test.txt`:

```text
-------------------------
cmd: echo
arg: hello
arg: world
cin_file:
cin_mode: term
cout_file:
cout_mode: pipe
next_mode: any
-------------------------
cmd: sort
cin_file:
cin_mode: pipe
cout_file:
cout_mode: pipe
next_mode: any
-------------------------
cmd: uniq
cin_file:
cin_mode: pipe
cout_file: test.txt
cout_mode: file
next_mode: any
-------------------------
```
