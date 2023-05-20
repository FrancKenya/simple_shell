#include "main.h"

/**
 * _strcmp - compare two strings
 * @str1: The first string under consideration
 * @str2: The second string
 * Return: An integer value less than, equal to or greater than 0
 */
int _strcmp(char *str1, char *str2)
{
	int i;

	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
	}

	return (str1[i] - str2[i]);
}

/**
 * _strdup - duplicate a string
 * @str: The string to be duplicated
 * Return: The address of the new string
 */
char *_strdup(char *str)
{
	char *new;
	int len, i;

	len = _strlen(str);
	new = malloc(sizeof(char) * (len + 1));
	for (i = 0; i < len; i++)
	{
		new[i] = str[i];
	}
	new[i] = '\0';
	return (new);
}

/**
 * _strncmp - compare the first n strings
 * @str1: String 1
 * @str2: String 2
 * @n: The first n characters to compare
 * Return: An integer value
 */
int _strncmp(const char *str1, const char *str2, int n)
{
	int i;

	for (i = 0; i < n && (str1[i] || str2[i]); i++)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}

	}
	return (0);
}
