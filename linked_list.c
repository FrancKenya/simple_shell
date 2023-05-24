#include "main.h"

/**
 * linked_path - generates a linked list for each directory of the PATH
 * environment variable value
 * @str: The string of the PATH environment variable value
 * @delim: The deliminiter to use in splitting path
 * @head: The head node of the linked list
 * Return: A linked list of the directory in the PATH environment variable
 */
path *linked_path(char *str, char *delim, path **head)
{
	char *dupstr, *token, *string;
	path *mem, *temp;

	if (!str || !delim)
		return (NULL);

	dupstr = _strdup(str);
	if (!dupstr)
		return (NULL);

	token = strtok(dupstr, delim);
	while (token != NULL)
	{
		mem = malloc(sizeof(path));
		string = _strdup(token);
		if (!string || !mem)
		{
			free(dupstr);
			return (NULL);
		}
		mem->str = string;
		mem->next = NULL;
		if (!(*head))
		{
			*head = mem;
		}
		else
		{
			temp->next = mem;
		}
		temp = mem;
		token = strtok(NULL, delim);
	}
	free(dupstr);

	return (*head);
}

/**
 * free_link - free the memory allocated to the linked list
 * @head: The head node of the linked list
 * Return: Void
 */
void free_link(path *head)
{
	path *temp;

	if (!head)
	{
		return;
	}
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->str);
		free(temp);
	}
}
