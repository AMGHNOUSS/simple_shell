#include "main.h"

/**
 * _strcmp - compare two strings
 * @s1: string 1
 * @s2: string 2
 * Return: int that tells num spaces in between, 0 if exactly the same string
 */

int _strcmp(char *s1, char *s2)
{
	int x = 0;

	while (*(s1 + x) == *(s2 + x) && *(s1 + x))
		x++;

	if (*(s2 + x))
		return (*(s1 + x) - *(s2 + x));
	else
		return (0);
}
