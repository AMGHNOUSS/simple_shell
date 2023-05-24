#include "shell.h"

/**
 * ctrl_c - ignore Ctrl-C input and prints prompt again
 * @n: takes in int from signal
 */
void ctrl_c(int n)
{
	(void)n;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * built_in - handles builtins
 * @env: enviroment variable
 * @num: take in nth user command typed to write error message
 * @command: command to free
 * Return: 1 if acted on builtin, else 0
 */
int built_in(char **token, list_t *env, int num, char **command)
{
	int x = 0;

	if (_strcmp(token[0], "exit") == 0)
	{
		x = __exit(token, env, num, command);
	}
	else if (_strcmp(token[0], "env") == 0)
	{
		_env(token, env);
		x = 1;
	}
	else if (_strcmp(token[0], "cd") == 0)
	{
		x = _cd(token, env, num);
	}
	else if (_strcmp(token[0], "setenv") == 0)
	{
		_setenv(&env, token);
		x = 1;
	}
	else if (_strcmp(token[0], "unsetenv") == 0)
	{
		_unsetenv(&env, token);
		x = 1;
	}
	return (x);
}

/**
 * ignore_space - return string without spaces in front
 * @str: string
 * Return: new string
 */
char *ignore_space(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

/**
 * ctrl_D - exits program if Ctrl-D is input
 * @i: characters read via get_line
 * @command: user's typed in command
 * @env: enviroment variable linked list
 */
void ctrl_D(int i, char *command, list_t *env)
{
	if (i == 0)
	{
		free(command);
		free_linked_list(env);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
}

/**
 * prompt - repeatedly prompts user and executes user's cmds if applicable
 * @en: envrionment variables
 * Return: 0 on success
 */
int prompt(char **en)
{
	list_t *env;
	size_t p = 0, q = 0;
	int cdn = 0, xt = 0;
	char *command, *n_command, **token;

	env = env_linked_list(en);
	do {
		cdn++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		else
			non_interactive(env);
		signal(SIGINT, ctrl_c);
		command = NULL;
		p = 0;
		p = get_line(&command);
		ctrl_D(p, command, env);
		n_command = command;
		command = ignore_space(command);
		q = 0;
		while (command[q] != '\n')
			q++;
		command[q] = '\0';
		if (command[0] == '\0')
		{
			free(n_command);
			continue;
		}
		token = NULL;
		token = _str_tok(command, " ");
		if (n_command != NULL)
			free(n_command);
		xt = built_in(token, env, cdn, NULL);
		if (xt)
			continue;
		xt = _execve(token, env, cdn);
	} while (1);
	return (xt);
}
