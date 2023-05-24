#include "main.h"

/**
 * main - A simple c shell program
 * @ac: The number of arguments supplied to the main function
 * @argv: The vector of argument supplied to to the main function
 * @env: The vector of the shell environment variable
 * Return: Always 0 (Success)
 */
int main(int ac, char **argv, char **env)
{
	(void) ac;

	if (isatty(0))
		shell_1(argv[0], env);
	else
		shell_1(argv[0], env);

	return (0);
}
