#include "main.h"

/**
 * handler - handle signal ctrl+c
 * @signum: The signal number
 * Return: Void
 */
void handler(int signum)
{
	char *new = S_NAME;

	(void) signum;
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, new, _strlen(new));
}

/**
 * form_error - forms the error message displayed for an invalid input
 * @str1: The name of the shell executable
 * @str2: The name of the command supplied to the shell
 * Return: The error message to be printed on the screen
 */
char *form_error(char *str1, char *str2)
{
	int i, len_str1 = _strlen(str1), len_str2 = _strlen(str2), total;
	int j = 0, k = 0, m = 0, str1_and_trail, trail_and_str2;
	char *message, *not_found = ": not found", *trailing = ": 1: ";

	str1_and_trail = len_str1 + _strlen(trailing);
	trail_and_str2 = str1_and_trail + len_str2;
	total = trail_and_str2 + _strlen(not_found);
	message = malloc(sizeof(char) * (total + 2));
	if (!message)
		return (NULL);

	for (i = 0; i < total; i++)
	{
		if (i < len_str1)
			message[i] = str1[i];
		else if (i >= len_str1 && i < (str1_and_trail))
		{
			message[i] = trailing[j];
			j++;
		}
		else if (i >= (str1_and_trail) && i < (trail_and_str2))
		{
			message[i] = str2[k];
			k++;
		}
		else
		{
			message[i] = not_found[m];
			m++;
		}
	}
	message[i] = '\n';
	message[i + 1] = '\0';

	return (message);
}

/**
 * null_command - prints the message for a null command
 * @exe: The name of the executable running
 * @argvc: Command line argument supplied to the shell
 * Return: Void
 */
void null_command(char *exe, char **argvc)
{
	char *error_message;

	error_message = form_error(exe, argvc[0]);
	write(STDOUT_FILENO, error_message,
	      _strlen(error_message));
	free(error_message);
	free_vector(argvc);
}

/**
 * exec_process - Execute a command line argument
 * @prompt: The command line string
 * @exe: The name of the executable shell
 * @env: The environment variable of the parent process
 * Return: Void
 */
void exec_process(char *prompt, char *exe, char **env)
{
	int flag;
	char **argvc;
	struct stat fileinfo;

	argvc = vectorize(prompt, " ");
	argvc[0] = check_path(argvc[0], env);
	flag = stat(argvc[0], &fileinfo);
	if (flag == 0)
		create_process(argvc);
	else
		null_command(exe, argvc);
}

/**
 * shell_1 - calls the shell with prompt "#cisfun$"
 * @env: string array of shell environment variables
 * @exe: The name of the executable file
 * Return: void
 */
void shell_1(char *exe, char **env)
{
	int i;
	size_t char_count;
	char *sysinfo, *prompt = NULL;

	signal(SIGINT, handler);
	while (1)
	{
		sysinfo = S_NAME;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, sysinfo, _strlen(sysinfo));
		char_count = getline(&prompt, &char_count, stdin);
		if ((int) char_count == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			free(prompt);
			exit(0);
		}

		prompt = replace(prompt, '\n');
		if (_strlen(prompt) == 0)
			continue;

		if (_strcmp(prompt, "exit") == 0)
			break;

		if (_strcmp(prompt, "env") == 0)
			for (i = 0; env[i] != NULL; i++)
			{
				write(STDOUT_FILENO, env[i], _strlen(env[i]));
				write(STDOUT_FILENO, "\n", 1);
			}

		exec_process(prompt, exe, env);

		if (!isatty(STDIN_FILENO))
			break;

	}
	free(prompt);
}
