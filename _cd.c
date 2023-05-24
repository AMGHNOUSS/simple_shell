#include "shell.h"

/**
 * c_strcat - concatenate two strings ignoring the first character
 * @dest: string to be appended to
 * @src: string to append
 * Return: concatenated string
 */
char *c_strcat(char *dest, char *src)
{
	int sz = 0, sz1 = 0, szt = 0, y = 0;

	while (dest[sz] != '\0')
	{
		sz++;
		szt++;
	}
	while (src[sz1] != '\0')
	{
		sz1++;
		szt++;
	}

	dest = _realloc(dest, sz, sizeof(char) * szt + 1);

	y = 1;
	while (src[y] != '\0')
	{
		dest[sz] = src[y];
		sz++;
		y++;
	}
	dest[sz] = '\0';

	return (dest);
}

/**
 * c_setenv - custom _setenv by concatenating string first before setting
 * @env: environmental variable linked list
 * @name: environmental variable name
 * @dir: directory path
 * Return: 0 on success
 **/
int c_setenv(list_t **env, char *name, char *dir)
{
	int idx = 0, y = 0;
	char *cat;
	list_t *holder;

	cat = _strdup(name);
	cat = _strcat(cat, "=");
	cat = _strcat(cat, dir);
	idx = find_env(*env, name);

	holder = *env;
	while (y < idx)
	{
		holder = holder->next;
		y++;
	}
	free(holder->var);
	holder->var = _strdup(cat);
	free(cat);
	return (0);
}

/**
 * cd_only - change directory to home
 * @env: environment linked list to update PATH and OLDPWD
 * @current:  current working directotry
 */
void cd_only(list_t *env, char *current)
{
	char *home = NULL;

	home = get_env("HOME", env);
	c_setenv(&env, "OLDPWD", current);
	free(current);
	if (access(home, F_OK) == 0)
		chdir(home);
	current = NULL;
	current = getcwd(current, 0);
	c_setenv(&env, "PWD", current);
	free(current);
	free(home);
}
/**
 * cd_execute - executes the cd
 * @env:  environment linked list to update PATH and OLDPWD
 * @current:  current working directotry
 * @dir:  directory path to change to
 * @str:  the 1st argument to write out error
 * @num:  the line number to write out error
 * Return: 0 if success 2 if fail
 */
int cd_execute(list_t *env, char *current, char *dir, char *str, int num)
{
	int x = 0;

	if (access(dir, F_OK) == 0)
	{
		c_setenv(&env, "OLDPWD", current);
		free(current);
		chdir(dir);
		current = NULL;
		current = getcwd(current, 0);
		c_setenv(&env, "PWD", current);
		free(current);
	}
	else
	{
		cant_cd_to(str, num, env);
		free(current);
		x = 2;
	}
	return (x);
}

/**
 * _cd - change directory
 * @str: user's typed in command
 * @env: enviroment linked list to retrieve HOME and OLDPWD paths
 * @num: nth user command, to be used at error message
 * Return: 0 if success 2 if failed
 */
int _cd(char **str, list_t *env, int num)
{
	char *current = NULL, *dir = NULL;
	int xt = 0;

	current = getcwd(current, 0);
	if (str[1] != NULL)
	{
		if (str[1][0] == '~')
		{
			dir = get_env("HOME", env);
			dir = c_strcat(dir, str[1]);
		}
		else if (str[1][0] == '-')
		{
			if (str[1][1] == '\0')
				dir = get_env("OLDPWD", env);
		}
		else
		{
			if (str[1][0] != '/')
			{
				dir = getcwd(dir, 0);
				dir = _strcat(dir, "/");
				dir = _strcat(dir, str[1]);
			}
			else
				dir = _strdup(str[1]);
		}
		xt = cd_execute(env, current, dir, str[1], num);
		free(dir);
	}
	else
		cd_only(env, current);
	free_double_ptr(str);
	return (xt);
}
