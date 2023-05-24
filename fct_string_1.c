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
* my_strcspn - gets the length of a prefix
* @str1: string to be searched
* @str2: string to be used
* Return: index at which char in str1 exists in str2
*/

int my_strcspn(char *str1, char *str2)
{
	int len = 0;
	int i;

	for (i = 0; str1[i] != '\0'; i++)
	{
		if (my_strchr(str2, str1[i]) != NULL)
			break;
		len++;
	}
	return (len);
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
* my_strspn - gets the length of a prefix substring
* @str1: string to be searched
* @str2: string to be used
* Return: number of bytes in the initial segment of 5 which are part of accept
*/

int my_strspn(char *str1, char *str2)
{
	int i = 0;
	int match = 0;

	while (str1[i] != '\0')
	{
		if (my_strchr(str2, str1[1]) == NULL)
			break;
		match++;
		i++;
	}
	return (match);
}

/**
* my_strchr - locates a char in a string
* @s: string to be searched
* @c: char to be cheacked
* Return: pointer to the first occurrence of c in s
*/

char *my_strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] != c && s[i] != '\0'; i++)
		;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
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
