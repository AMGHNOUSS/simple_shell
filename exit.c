#include "main.h"

/**
 * exit_shell - exits the shell
 *
 * @listssh: lists relevant (status and args)
 * Return: 0 on success.
 */
int exit_shell(lists_shell *listssh)
{
	unsigned int ustatus;
	int is_digit;
	int str_len;
	int big_number;

	if (listssh->args[1] != NULL)
	{
		ustatus = _atoi(listssh->args[1]);
		is_digit = _isdigit(listssh->args[1]);
		str_len = _strlen(listssh->args[1]);
		big_number = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			get_error(listssh, 2);
			listssh->status = 2;
			return (1);
		}
		listssh->status = (ustatus % 256);
	}
	return (0);
}
