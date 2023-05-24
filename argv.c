#include "main.h"

/**
 * count - count the number of arguments supplied via the command line
 * @str: The string of the command line argument
 * Return: A value equal or greater that 0
 */
int count(char *str)
{
	int i = 0;
	char *dup, *token;

	dup = _strdup(str);
	if (!dup)
	{
		return (0);
	}
	token = strtok(dup, " ");
	while (token)
	{
		i++;
		token = strtok(NULL, " ");
	}

	free(dup);
	return (i);
}

/**
 * vectorize - creates a vector of strings seperated by a delimiter
 * @string: The string supplied to the command line
 * @delim: The delimiter to seperate the supplied string
 * Return: A pointer to an array of string
 */
char **vectorize(char *string, char *delim)
{
	int num_of_str, i = 0;
	char *str_dup, **vector, *token;

	str_dup = _strdup(string);
	if (!str_dup)
	{
		return (NULL);
	}
	num_of_str = count(str_dup) + 1;
	vector = malloc(sizeof(char *) * num_of_str);
	if (!vector)
	{
		free(str_dup);
		return (NULL);
	}

	token = strtok(str_dup, delim);
	while (token)
	{
		vector[i] = malloc(_strlen(token) + 1);
		if (!vector[i])
		{
			free(str_dup);
			free_vector(vector);
			return (NULL);
		}

		_strcpy(vector[i], token);
		i++;
		token = strtok(NULL, " ");
	}

	vector[i] = NULL;
	free(str_dup);
	return (vector);
}

/**
 * free_vector - frees the memory allocated to an argument vector
 * @vector:  The argument vector to be freed
 * Return: Void
 */
void free_vector(char **vector)
{
	int i;

	for (i = 0; vector[i] != NULL; i++)
	{
		free(vector[i]);
	}
	free(vector);
}
