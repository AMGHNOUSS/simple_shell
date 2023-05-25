#include "main.h"

/**
 * free_lists - frees lists structure
 *
 * @listssh: lists structure
 * Return: no return
 */
void free_lists(lists_shell *listssh)
{
	unsigned int i;

	for (i = 0; listssh->_environ[i]; i++)
	{
		free(listssh->_environ[i]);
	}

	free(listssh->_environ);
	free(listssh->pid);
}

/**
 * set_lists - Initialize lists structure
 *
 * @listssh: lists structure
 * @av: argument vector
 * Return: no return
 */
void set_lists(lists_shell *listssh, char **av)
{
	unsigned int i;

	listssh->av = av;
	listssh->input = NULL;
	listssh->args = NULL;
	listssh->status = 0;
	listssh->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	listssh->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		listssh->_environ[i] = _strdup(environ[i]);
	}

	listssh->_environ[i] = NULL;
	listssh->pid = aux_itoa(getpid());
}

/**
 * main - Entry point
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	lists_shell listssh;
	(void) ac;

	signal(SIGINT, get_sigint);
	set_lists(&listssh, av);
	shell_loop(&listssh);
	free_lists(&listssh);
	if (listssh.status < 0)
		return (255);
	return (listssh.status);
}
