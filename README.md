## Description

This repo has our custom shell project, which attempts to replicate some of the
processes of the 'sh' shell or 'bash' shell.
For more information view the blog post of Ibrahim Morketa & Simegnew Misganaw
[here](https://medium.com/@ibrahimbsc8/simple-shell-a-custom-shell-command-line-interpreter-a0d11d5b219f)

### C language standard functions and system calls utilized

`access`, `chdir`, `close`, `closedir`, `execve`, `exit`, `fork`,
`free`, `fstat`, `getcwd`, `getline`, `kill`, `lstat`, `malloc`,
`open`, `opendir`, `perror`, `read`, `readdir`, `signal`, `stat`,
`strtok`, `wait`, `waitpid`, `wait3`, `wait4`, `write`, `_exit`

## Brief Synopsis

All files in this repository are designed to compile with GNU compiler
collection '`gcc`' in the linux environment from '`Ubuntu 20.04
LTS`'.  When compiled, the executable file replicates a 'shell' or command line
interpreter, which is a user interface used for access to an operating system's
services.  This shell has a set of custom built-in commands, and also integrates
with other commands located in the system's PATH.  Output and functionality from
commands is designed to replicate output from the shell `sh` (dash) and some
bash commands.

## Usage

### compile

```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

**Compile with Make**: `make all`

### executing the program

**interactive mode**: `$ ./hsh`

**non-interactive mode**: `$ echo "ls -la" | ./hsh`

### usage of arsine in interactive mode

Here is an example usage of the ls
command with flags.  This command lists directory contents.

```
$ ls -la
```
                                                         

## Ref
* Olumide Micheal Tolulope <olumidemicheal7@gmail.com>
* Ahmed Gbadamosi
