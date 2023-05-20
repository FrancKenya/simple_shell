#include "main.h"

/**
 * child_process - executes a new program in a child process
 * @argv: The argument vector supplied of the command line argument
 * Return: Nill
 */
void child_process(char **argv)
{
	char *error_message;

	if (execve(argv[0], argv, NULL) == -1)
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
void create_process(char **argv)
{
	int i, child;

	child = fork();
	if (child == 0)
	{
		child_process(argv);
	}
	else
	{
		wait(&i);
		free_vector(argv);
	}
}
