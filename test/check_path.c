#include "main.h"

/**
 * _get_env - searches for an environment variables from the parent process
 * variable
 * @name: The name of the variable whose value we want to get
 * @environ: The string array of environment variables and their values
 * Return: Returns the value of the variable
 */
char *_get_env(const char *name, char **environ)
{
	int i, len;
	char **env = environ;

	len = _strlen(name);
	for (i = 0; env[i] != NULL; i++)
	{
		if (_strncmp(name, env[i], len) == 0 &&
		    env[i][len] == '=')
			return (env[i] + len + 1);
	}

	return (NULL);
}

/**
 * concat - concatenate the command to the path directories of the path
 * variable
 * @command: The command supplied via the command line
 * @dir: The directory in the path variable
 * Return: A pointer to the concatenated string
 */
char *concat(char *dir, char *command)
{
	int i, j = 0, com_len, dir_len, total;
	char *new_str;

	com_len = _strlen(command);
	dir_len = _strlen(dir);
	total = com_len + dir_len + 2;
	new_str = malloc(sizeof(char) * total);
	if (!new_str)
		return (NULL);

	for (i = 0; i < total; i++)
	{
		if (i < dir_len)
			new_str[i] = dir[i];
		else if (i == dir_len)
			new_str[i] = '/';
		else if (i < total)
		{
			new_str[i] = command[j];
			j++;
		}
		else
			new_str[i] = '\0';
	}

	return (new_str);
}
/**
 * check_path - check if a command exist in a path environment
 * @string: The string of the path variable
 * @environ: Array of strings holding the process environment variables
 * and their values
 * Return: A string of a path to a full command
 */
char *check_path(char *string, char **environ)
{
	int flag = 0;
	char *dir = NULL, *value, *str;
	path *path = NULL, *temp;
	struct stat fileinfo;

	str = _strdup(string);
	if (stat(str, &fileinfo) == 0)
		return (str);

	value = _get_env("PATH", environ);
	if (!value)
		return (NULL);

	path = linked_path(value, ":", &path);
	temp = path;
	while (temp != NULL)
	{
		free(dir);
		dir = concat(temp->str, str);
		if (stat(dir, &fileinfo) == 0)
		{
			flag = 1;
			break;
		}
		temp = temp->next;
	}

	free_link(path);
	if (!flag)
	{
		free(dir);
		return (str);
	}
	free(str);
	return (dir);
}
