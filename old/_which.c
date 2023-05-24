#include "main.h"

/**
 * _which - fleshes out command by appending it to a matching PATH directory
 * @str: first command user typed into shell
 * @env: environmental variable
 * Return: a copy of fleshed out command
 */
char *_which(char *str, list_t *env)
{
	char *pth, *cat = NULL, **toks;
	int x = 0;

	pth = get_env("PATH", env);
	toks = c_str_tok(pth, ":");
	free(pth);

	x = 0;
	while (toks[x] != NULL)
	{
		if (toks[x][0] == '\0')
			cat = getcwd(cat, 0);
		else
			cat = _strdup(toks[x]);
		cat = _strcat(cat, "/");
		cat = _strcat(cat, str);
		if (access(cat, F_OK) == 0)
		{
			free_double_ptr(toks);
			return (cat);
		}
		free(cat);
		x++;
	}
	free_double_ptr(toks);
	return (str);
}
