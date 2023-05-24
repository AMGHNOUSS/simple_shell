#include "shell.h"

/**
 * c_strdup - custom string duplication; excludes beginning bytes
 * @str: string to duplicate
 * @cs: number of bytes to exclude
 * Return: string
 */
char *c_strdup(char *str, int cs)
{
	char *duplicate_str;
	int x, sz = 0;

	if (str == NULL)
		return (NULL);

	while (*(str + sz))
		sz++;
	sz++;

	duplicate_str = malloc(sizeof(char) * (sz - cs));
	if (duplicate_str == NULL)
		return (NULL);

	x = 0;
	while (x < (sz - cs))
	{
		*(duplicate_str + x) = *(str + cs + x);
		x++;
	}
	return (duplicate_str);
}

/**
 * get_env - finds and returns a copy of the requested enviroment variable
 * @str: string to store it in
 * @env: entire set of enviroment variables
 * Return: copy of requested enviroment variable
 */
char *get_env(char *str, list_t *env)
{
	int x = 0, cs = 0;

	while (env != NULL)
	{
		x = 0;
		while ((env->var)[x] == str[x])
			x++;
		if (str[x] == '\0' && (env->var)[x] == '=')
			break;
		env = env->next;
	}

	while (str[cs] != '\0')
		cs++;
	cs++;
	return (c_strdup(env->var, cs));
}
