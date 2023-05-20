#include "shell.h"
#define MAX_C_LEN 100
#define MAX_PATH_LEN 100
void exit_builtin_handle(char **args);
void handle_env_builtin(char **args);
char *get_command_path(const char *command);
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
if (fgets(c, MAX_C_LEN, stdin) == NULL)
{
write(STDOUT_FILENO, "\n", 1);
exit(EXIT_SUCCESS); }
if (c[0] == '\n') /* check if input is empty */
{
continue; }
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
handle_env_builtin(args); /* called to check and handle env command */
exit_builtin_handle(args); /* checking exit command and exiting */
pid = fork();
if (pid == -1) /* check for errors after forking */
{
perror(argv[0]); /* display the error */
exit(EXIT_FAILURE); }
else if (pid == 0) /* child process */
{
if (execvp(args[0], args) < 0) /* check for execvp command fail */
{
perror(argv[0]); /* print the error */
exit(EXIT_FAILURE); }
exit(EXIT_SUCCESS); } /* if not failed exit successfully */
else
{
waitpid(pid, &status, 0); }} /* wait for child process to finish */
return (0); }
/**
* exit_builtin_handle - checks if command is 'exit' to exit
* @args: double pointer to argument input
* Return: void
*/
void exit_builtin_handle(char **args)
{
if (strcmp(args[0], "exit") == 0) /* checking for exit command */
{
exit(EXIT_SUCCESS); /* exit called successfully */
}
}
/**
* handle_env_builtin - called to print the current environment
* @args: double pointer to argument input
* Return: void
*/
void handle_env_builtin(char **args)
{
char **env =  environ; /* access the enviroment variables */
ssize_t len;

len = strlen(*env);
if (strcmp(args[0], "env") == 0)
{
while (*env != NULL)
{
write(STDOUT_FILENO, *env, len); /* print environment */
write(STDOUT_FILENO, "\n", 1); /* create new line */
env++;
}
}
}
/**
* get_command_path - handle PATH
* @command: constant pointer to command string
* Return: command path
*/

char *get_command_path(const char *command)
{
char *path, *path_token, *command_path;
const char *error_msg = "PATH not set\n";
const char *error_msg2 = "Memory allocation failed\n";

path = getenv("PATH");
if (path == NULL)
{
write(STDERR_FILENO, error_msg, strlen(error_msg));
return (NULL);
}

path_token = strtok(path, ":");
while (path_token != NULL)
{
command_path =  malloc(MAX_PATH_LEN);
if (command_path == NULL)
{
write(STDERR_FILENO, error_msg2, strlen(error_msg2));
return (NULL);
}
strncpy(command_path, path_token, MAX_PATH_LEN - 1);
strncat(command_path, "/", MAX_PATH_LEN - strlen(command_path) - 1);
strncat(command_path, command, MAX_PATH_LEN - strlen(command_path) - 1);
if (access(command_path, X_OK) == 0) /* check if executable */
{
return (command_path); /* when Command found in PATH */
}
free(command_path);
path_token = strtok(NULL, ":");
}
write(STDERR_FILENO, "Command not found\n", 18);
return (NULL); /* when command not found */
}
