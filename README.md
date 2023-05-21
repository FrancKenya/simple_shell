# ALX simple shell project
> This repository contains source code for the simple shell project on ALX

## General requirement
* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to (why?)
* Write a README with the description of your project
* You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker

## Compilation
The code was compiled in the manner below;
> `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## Description:
hsh is a straightforward interpreter for the UNIX command language. It is capable of reading commands from a file or standard input and executing them.

### How hsh operates:
* Displays a prompt and waits for a command from the user.
* Creates a child process to handle the command.
* Checks for built-ins, aliases in the PATH, and local executable programs.
* The child process executes the command along with its arguments.
* Once the command finishes executing, the program returns to the parent process and displays the prompt again.
* The program is then ready to accept a new command.
* To exit, either press Ctrl-D or enter "exit" (with or without specifying a status).

**hsh also functions in non-interactive mode.**

## Invocation:
Usage: `hsh [filename]`

To use hsh, compile all the .c files in the repository and execute the resulting executable.

hsh can be invoked in two ways;
* interactively:
  if hsh is invoked interactively then the shell is ready to accept input from the standard input just like `sh` command works

> Example:
  > `$ [command]`
* non-interactively:
  In this mode the shell is read input from a file

> Example:
  ```shell
  $ echo "/bin/ls" | ./hsh
  hsh main.c shell.c test_ls_2
  $
  $ cat test_ls_2
  /bin/ls
  /bin/ls
  $
  $ cat test_ls_2 | ./hsh
  hsh main.c shell.c test_ls_2
  hsh main.c shell.c test_ls_2
  $
  ```

## Command Execution
Upon receiving a command, hsh performs the following steps to process and execute it:

1. Tokenization: The command is tokenized into separate words using a space (" ") as the delimiter. The first word represents the command itself, while the remaining words serve as arguments for that command.

2. Builtin Execution: If the first character of the command is neither a forward slash () nor a dot (.), hsh searches for a matching shell builtin command in its list. If a builtin command with the specified name is found, hsh invokes and executes it accordingly.

3. Path Resolution: In case the command does not start with a forward slash () or a dot (.), and it is not a shell builtin, hsh proceeds to search each directory specified in the PATH environmental variable. This search aims to locate an executable file with the same name as the command.

4. Execution Environment: If the command begins with a forward slash () or a dot (.), or if the previous path resolution step successfully finds an executable file, hsh proceeds to execute the named program. Any remaining arguments are passed to the program within a separate execution environment.

By following these steps, hsh effectively processes and executes commands, providing flexibility in handling both builtins and external programs.

## Authors
|Name|Email|
|----|-----|
|Adekunle Adetunji|Adekunleadetunjiwilson@gmail.com|
|Francis Waihiga|franciswaihiga@gmail.com|