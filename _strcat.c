#include "main.h"

/**
 * _strcat - concatenate two strings
 * @dest: string to be appended to
 * @src: string to append
 * Return: concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int sz = 0, sz1 = 0, szt = 0,  x = 0;

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

	while (src[x] != '\0')
	{
		dest[sz] = src[x];
		sz++;
		x++;
	}
	dest[sz] = '\0';

	return (dest);
}
