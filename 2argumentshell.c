#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_C_LEN 100

/**
* main - writes a UNIX command line interpreter.
* @argc: argument count
* @argv: argument vector
* description: handles command lines with arguments using strtok()
* to create an array of arrguments and execvp instead of execve to execute
* command with its arguments.
* Return: (0) Success
*/

int main(int __attribute__((unused)) argc, char *argv[])
{
char c[MAX_C_LEN], *args[MAX_C_LEN], *token;
pid_t pid;
int status, i;

while (1)
{
write(STDOUT_FILENO, "shell$ ", 7); /* display prompt */
fflush(stdout);
if (fgets(c, MAX_C_LEN, stdin) == NULL) /* read and terminate if CTRL D */
{
write(STDOUT_FILENO, "\n", 1);
exit(EXIT_SUCCESS); }
if (c[strlen(c) - 1] == '\n') /* check for newline */
{
c[strlen(c) - 1] = '\0'; } /* remove new line */
i = 0;
token = strtok(c, " "); /* assign the delimiter to token */
while (token != NULL)  /* split uaing delimiter and store in args */
{
args [i++] = token;
token = strtok(NULL, " "); }
args[i] = NULL;
pid = fork();
if (pid == -1) /* check for errors after forking */
{
perror(argv[0]); /* display the error */
exit(EXIT_FAILURE); }
else if (pid == 0) /* child process */
{
if (execvp(args[0], args) == -1) /* check for execvp command fail */
{
perror(argv[0]); /* print the error */
exit(EXIT_FAILURE); }
exit(EXIT_SUCCESS); } /* if not failed exit successfully */
else
{
waitpid(pid, &status, 0); } /* wait for child process to finish */
}
return (0);
}
