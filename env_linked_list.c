#include "shell.h"

/**
 * env_linked_list - creates a linked list from enviroment variables
 * @env: enviroment variables
 * Return: linked list
 */
list_t *env_linked_list(char **env)
{
	list_t *head;
	int x = 0;

	head = NULL;
	while (env[x] != NULL)
	{
		add_end_node(&head, env[x]);
		x++;
	}
	return (head);
}

/**
 * _env - prints enviroment variables
 * @str: user's command into shell
 * @env: enviroment variables
 * Return: 0 on success
 */
int _env(char **str, list_t *env)
{
	free_double_ptr(str);
	print_list(env);
	return (0);
}
