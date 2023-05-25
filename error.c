#include "main.h"

/**
 * get_error - calls the error according the builtin, syntax or permission
 * @listssh: lists structure that contains arguments
 * @eval: error value
 * Return: error
 */
int get_error(lists_shell *listssh, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = error_env(listssh);
		break;
	case 126:
		error = error_path_126(listssh);
		break;
	case 127:
		error = error_not_found(listssh);
		break;
	case 2:
		if (_strcmp("exit", listssh->args[0]) == 0)
			error = error_exit_shell(listssh);
		else if (_strcmp("cd", listssh->args[0]) == 0)
			error = error_get_cd(listssh);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	listssh->status = eval;
	return (eval);
}
