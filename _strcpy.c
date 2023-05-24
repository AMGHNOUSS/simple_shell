#include "main.h"

/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest
 * @dest: copy source to this buffer
 * @src: this is the source to copy
 * Return: copy of original source
 */

char *_strcpy(char *dest, char *src)
{
	int x, sz;

	for (sz = 0; src[sz] != '\0'; sz++)
		;

	for (x = 0; x <= sz; x++)
		dest[x] = src[x];
	return (dest);
}
