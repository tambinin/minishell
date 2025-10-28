# Minishell
![42 School Project](https://img.shields.io/badge/42-Project-white?style=flat&logo=42&color=000)

## Description
A simple shell implementation that replicates basic bash functionality.

### Requirements
- Unix-like operating system
- GCC compiler
- GNU Make

### Features
#### Mandatory
- Display a prompt while waiting for a new command
- Working history
- Search and launch executables based on PATH variable
- Handle quotes (`'` and `"`)
- Implement redirections:
  - `<` (input)
  - `>` (output)
  - `<<` (heredoc)
  - `>>` (append)
- Implement pipes (`|`)
- Handle environment variables (`$` followed by characters)
- Handle `$?` (exit status)
- Handle signals (`ctrl-C`, `ctrl-D`, `ctrl-\`)
- Builtins:
  - `echo` with option `-n`
  - `cd` with relative or absolute path
  - `pwd` without options
  - `export` without options
  - `unset` without options
  - `env` without options
  - `exit` without options

### Building
```bash
make        # Compile project
make clean  # Remove objects
make fclean # Remove objects and binary
make re     # fclean + all
```

### Usage
```bash
./minishell
```

### Testing
- Basic commands:
```bash
ls -la
echo "Hello World"
cd ..
pwd
```
- Pipes and redirections:
```bash
ls | grep ".c"
echo "test" > outfile
cat < infile
```

### Resources
- [Unix Shells](https://en.wikipedia.org/wiki/Unix_shell)
- [Writing Your Own Shell](https://www.gnu.org/software/libc/manual/html_node/Implementing-a-Shell.html)

### Authors
- @tambinin (42 login)
- [Your project partner if applicable]
