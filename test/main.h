#ifndef MAIN_H
#define MAIN_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>

/**
 * struct path - creates a linked list to a PATH environ variable value
 * @str: The data section of the linked list
 * @next: The pointer or reference to the next node
 */
typedef struct path
{
	char *str;
	struct path *next;
} path;

char *_get_env(const char *name, char **environ);
int num_variables(void);
void print_env(void);
void child_process(char **path);
void shell_1(char *exe, char **env);
char **vectorize(char *string, char *delim);
void free_vector(char **vector);
int count(char *str);
char *check_path(char *string, char **environ);
path *linked_path(char *str, char *delim, path **head);
void free_link(path *head);
int _strlen(const char *str);
char *replace(char *str, char repl);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
void create_process(char **argv);
int _strcmp(char *str1, char *str2);
int _strncmp(const char *str1, const char *str2, int n);

#endif
