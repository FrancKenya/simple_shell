#include "main.h"

/**
 * _strcpy - copies a string to another memory address
 * @dest: The address whose values are to be modified
 * @src: The address where values are to be copied
 *
 * Return: Returns a null value
 */
char *_strcpy(char *dest, char *src)
{
	int i, len;

	len = _strlen(src);
	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * replace - replace the first occurrence of a character from a string
 * @str: The string we want to replace character in
 * @repl: The replacement string
 * Return: Return the address to the new string
 */
char *replace(char *str, char repl)
{
	int i, j;
	char *new, *dup_str;

	if (!str || !repl)
	{
		return (NULL);
	}
	dup_str = _strdup(str);
	free(str);
	if (!dup_str)
	{
		return (NULL);
	}
	for (i = 0; dup_str[i] != '\0'; i++)
		if (dup_str[i] == repl)
		{
			break;
		}

	new = malloc(sizeof(char) * (i + 1));
	if (!new)
	{
		return (NULL);
	}
	for (j = 0; j < i; j++)
		new[j] = dup_str[j];
	new[j] = '\0';

	free(dup_str);
	return (new);
}

/**
 * _strlen - count the len of a string
 * @str: The string we want to count its length
 * Return: An integer
 */
int _strlen(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * is_space - checks if the argument provided is just an empty space
 * @str: The supplied string
 * Return: An interger value of either zero or one
 */
int is_space(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			return (0);
		}
	}
	return (1);
}
