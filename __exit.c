#include "shell.h"

/**
 * c_atoi - custom atoi converts string to int
 * @s: string
 * Return: number if success,else -1
 */
int c_atoi(char *s)
{
	int x = 0;
	unsigned int cnt = 0;

	while (s[x] != '\0')
	{
		if (s[x] >= '0' && s[x] <= '9')
			cnt = cnt * 10 + (s[x] - '0');
		if (s[x] > '9' || s[x] < '0')
			return (-1);
		x++;
	}
	return (cnt);
}

/**
 * __exit - frees user input and then exits with a value
 * @str: user's command into shell
 * @env:  environment variable to free at error
 * @num:  nth user command line input to print in error message
 * @command:  command to free
 * Return: 0 if success else 2
 */
int __exit(char **str, list_t *env, int num, char **command)
{
	int ls = 0;

	if (str[1] != NULL)
		ls = c_atoi(str[1]);

	if (ls == -1)
	{
		illegal_number(str[1], num, env);
		free_double_ptr(str);
		return (2);
	}
	free_double_ptr(str);
	free_linked_list(env);
	if (command != NULL)
		free_double_ptr(command);
	exit(ls);
}
