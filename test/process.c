#include "main.h"

/**
 * child_process - executes a new program in a child process
 * @argv: The argument vector supplied of the command line argument
 * Return: Nill
 */
void child_process(char *var, char **argv, char **env)
{
	char *error_message;

	if (execve(var, argv, env) == -1)
	{
		error_message = "There was an error with execve\n";
		write(STDOUT_FILENO, error_message, _strlen(error_message));
		return;
	}
}

/**
 * create_process - execute a command supplied to the command line in a new
 * process
 * @argv: The argument vector supplied to the command line
 * Return: Void
 */
void create_process(char *var, char **argv, char **env)
{
	int i, child;

	child = fork();
	if (child == 0)
	{
		child_process(var, argv, env);
	}
	else
	{
		wait(&i);
		free(var);
		free_vector(argv);
	}
}
