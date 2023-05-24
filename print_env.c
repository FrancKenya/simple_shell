#include "main.h"

/**
 * printenv - print the content of the current working environment
 * @env: The environment variable
 * Return: Void
 */
void printenv(char **env)
{
	int i;

	while (env[i])
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
