#include "shell.h"
/**
* my_strcmp - compare two strings
* @first: first string to be compared
* @second: second string to be compared
* Return: difference of the two strings
*/

int my_strcmp(char *first, char *second)
{
	int i = 0;

	while (first[i] != '\0')
	{
		if (first[i] != second[i])
			break;
		i++;
	}
	return (first[i] - second[i]);
}
/**
* my_strcat - concatenates two strings
* @destination: string to be concatenated to
* @source: string to concatenate
* Return: address of the new string
*/

char *my_strcat(char *destination, char *source)
{
	char *new_string = NULL;
	int len_dest = my_strlen(destination);

	new_string = malloc(sizeof(*new_string) * (len_dest + len_source + 1));
	my_strcpy(destination, new_string);
	my_strcpy(source, new_string + len_dest);
	new_string[len_dest + len_source] = '\0';
	return (new_string);
}
/**
 * _strlen - count length
 * @string: string
 * Return: length of the string
 */
int _strlen(char *string)
{
	int len = 0;

	if (string == NULL)
		return (len);
	for (; string[len] != '\0'; len++)
		;
	return (len);
}
/**
 * _strcpy - copies the string pointer
 * @dest: String
 * @src: String
 * Return: String
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
/**
 * _strdup - pointer to a newly allocated space in memory,
 * @str: String
 * Return: String
 */
char *_strdup(char *str)
{
	char *duplicat_str;
	int x, sz = 0;

	if (str == NULL)
		return (NULL);
	while (*(str + sz))
		sz++;
	sz++;
	duplicat_str = malloc(sizeof(char) * sz);
	if (duplicat_str == NULL)
		return (NULL);
	x = 0;
	while (x < sz)
	{
		*(duplicat_str + x) = *(str + x);
		x++;
	}
	return (duplicat_str);
}
