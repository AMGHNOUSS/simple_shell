#include "shell.h"

/**
 * free_double_ptr - free malloced arrays
 * @str: array of strings
 */
void free_double_ptr(char **str)
{
	int x = 0;

	while (str[x] != NULL)
	{
		free(str[x]);
		x++;
	}
	free(str);
}
