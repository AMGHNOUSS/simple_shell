#include "shell.h"

/**
 * find_env - find given environment variable in linked list
 * @env: environment variable linked list
 * @str: variable name
 * Return: idx of node in linked list
 */
int find_env(list_t *env, char *str)
{
	int j = 0, idx = 0;

	while (env != NULL)
	{
		j = 0;
		while ((env->var)[j] == str[j])
			j++;
		if (str[j] == '\0')
			break;
		env = env->next;
		idx++;
	}
	if (env == NULL)
		return (-1);
	return (idx);
}

/**
 * _unsetenv - remove node in environment linked list
 * @env: linked list
 * @str: user's typed in command
 * Return: 0 on success
 */
int _unsetenv(list_t **env, char **str)
{
	int idx = 0, y = 0;

	if (str[1] == NULL)
	{
		write(STDOUT_FILENO, "Less arguments provided\n", 18);
		free_double_ptr(str);
		return (-1);
	}
	idx = find_env(*env, str[1]);
	free_double_ptr(str);
	if (idx == -1)
	{
		write(STDOUT_FILENO, "Not found\n", 12);
		return (-1);
	}
	y = delete_nodeint_at_index(env, idx);
	if (y == -1)
	{
		write(STDOUT_FILENO, "Not found\n", 12);
		return (-1);
	}
	return (0);
}

/**
 * _setenv - create or modify existing environment variable in linked list
 * @env: linked list
 * @str: user's typed in command
 * Return: 0 on success else 1
 */
int _setenv(list_t **env, char **str)
{
	int idx = 0, x = 0;
	char *cat;
	list_t *holder;

	if (str[1] == NULL || str[2] == NULL)
	{
		write(STDOUT_FILENO, "Too few arguments\n", 18);
		free_double_ptr(str);
		return (-1);
	}
	cat = _strdup(str[1]);
	cat = _strcat(cat, "=");
	cat = _strcat(cat, str[2]);
	idx = find_env(*env, str[1]);
	if (idx == -1)
	{
		add_end_node(env, cat);
	}
	else
	{
		holder = *env;
		while (x < idx)
		{
			holder = holder->next;
			x++;
		}
		free(holder->var);
		holder->var = _strdup(cat);
	}
	free(cat);
	free_double_ptr(str);
	return (0);
}
