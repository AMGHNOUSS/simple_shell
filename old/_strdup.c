#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 * @str: string to duplicate
 * Return: pointer to duplicated string in allocated memory
 */
char *_strdup(char *str)
{
	char *duplicate_str;
	int x, sz = 0;

	if (str == NULL)
		return (NULL);

	while (*(str + sz))
		sz++;

	sz++;
	duplicate_str = malloc(sizeof(char) * sz);
	if (duplicate_str == NULL)
		return (NULL);

	x = 0;
	while (x < sz)
	{
		*(duplicate_str + x) = *(str + x);
		x++;
	}
	return (duplicate_str);
}
