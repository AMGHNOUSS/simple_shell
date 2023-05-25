#include "main.h"

/**
 * exec_line - finds builtins and commands
 *
 * @listssh: lists relevant (args)
 * Return: 1 on success.
 */
int exec_line(lists_shell *listssh)
{
	int (*builtin)(lists_shell *listssh);

	if (listssh->args[0] == NULL)
		return (1);

	builtin = get_builtin(listssh->args[0]);

	if (builtin != NULL)
		return (builtin(listssh));

	return (cmd_exec(listssh));
}
