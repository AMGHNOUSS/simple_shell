#include "shell.h"

/**
 * c_ignore - custom ignores spaces and newlines
 * @str: enviroment variables
 * Return: new string
 */
char *c_ignore(char *str)
{
	while (*str == ' ' || *str == '\n')
		str++;
	return (str);
}

/**
 * non_interactive - handles when user pipes commands into shell
 * @env: enviroment variables
 */
void non_interactive(list_t *env)
{
	size_t p = 0, q = 0;
	int cdn = 0, xt = 0;
	char *command = NULL, *n_command = NULL, **n_line, **token;

	p = get_line(&command);
	if (p == 0)
	{
		free(command);
		exit(0);
	}
	n_command = command;
	command = c_ignore(command);
	n_line = _str_tok(command, "\n");
	if (n_command != NULL)
		free(n_command);
	q = 0;
	while (n_line[q] != NULL)
	{
		cdn++;
		token = NULL;
		token = _str_tok(n_line[q], " ");
		xt = built_in(token, env, cdn, n_line);
		if (xt)
		{
			q++;
			continue;
		}
		xt = _execve(token, env, cdn);
		q++;
	}
	free_double_ptr(n_line);
	free_linked_list(env);
	exit(xt);
}
