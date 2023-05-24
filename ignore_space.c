#include "main.h"
/**
 * ignore_space - return string without spaces in front
 * @str: string
 * Return: new string
 */
char *ignore_space(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

