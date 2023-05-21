# ALX simple shell project
> This repository contains source code for the simple shell project on ALX

## General requirement
* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the\
options -Wall -Werror -Wextra -pedantic -std=gnu89
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl\
and betty-doc.pl
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to (why?)
* Write a README with the description of your project
* You should have an AUTHORS file at the root of your repository, listing all\
individuals having contributed content to the repository. Format, see Docker

## Compilation
The code was compiled in the manner below;
> `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## Description:
hsh is a straightforward interpreter for the UNIX command language. It is\
capable of reading commands from a file or standard input and executing them.

### How hsh operates:
* Displays a prompt and waits for a command from the user.
* Creates a child process to handle the command.
* Checks for built-ins, aliases in the PATH, and local executable programs.
* The child process executes the command along with its arguments.
* Once the command finishes executing, the program returns to the parent\
process and displays the prompt again.
* The program is then ready to accept a new command.
* To exit, either press Ctrl-D or enter "exit" (with or without specifying\
a status).

**hsh also functions in non-interactive mode.**

## Invocation:
Usage: `hsh [filename]`

To use hsh, compile all the .c files in the repository and execute the\
resulting executable.

hsh can be invoked in two ways;
* interactively
  if hsh is invoked interactively then the shell is ready to accept input from\
  the standard input just like `sh` command works
  Example:
  > `$ [command]`
* non-interactively
  In this mode the shell is read input from a file
  Example:
  ```
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

## Authors
|Name|Email|
|----|-----|
|Adekunle Adetunji|Adekunleadetunjiwilson@gmail.com|
|Francis Waihiga|franciswaihiga@gmail.com|