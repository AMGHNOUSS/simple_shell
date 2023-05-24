#include "main.h"
/**
 * _realloc - reallocates a memory
 * @ptr: pointer to the memory previously allocated
 * @old_size: Integer
 * @new_size: Integer
 * Return: pointer to the address
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *temp_block;
	unsigned int i;

	if (ptr == NULL)
	{
		temp_block = malloc(new_size);
		return (temp_block);
	}
	else if (new_size == old_size)
		return (ptr);
	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		temp_block = malloc(new_size);
		if (temp_block != NULL)
		{
			for (i = 0; i < min(old_size, new_size); i++)
				*((char *)temp_block + i) = *((char *)ptr + i);
			free(ptr);
			return (temp_block);
		}
		else
			return (NULL);
	}
}

/**
 * c_token_count - Counts the number of delimiters in a string.
 * @str: User's command typed into the shell.
 * @delim: Delimiter character ';'
 *
 * Return: Number of tokens.
 */
int c_token_count(char *str, char delim)
{
	int count = 0;

	while (*str != '\0')
	{
		if (*str == delim)
			count++;
		str++;
	}

	return count;
}

/**
 * c_str_tokenize - Tokenizes a string, handling continuous delimiters as empty tokens.
 * @str: User's command typed into the shell.
 * @delim: Delimiter string.
 *
 * Return: An array of tokens.
 */

char **c_str_tokenize(char *str, char *delim)
{
	int buffer_size = 0, i = 0, j = 0, k = 0, len = 0;
	char **tokens = NULL, delim_char;

	delim_char = delim[0];
	buffer_size = c_token_count(str, delim_char);
	tokens = malloc(sizeof(char *) * (buffer_size + 2));
	if (tokens == NULL)
		return NULL;

	while (str[len] != '\0')
		len++;

	while (j < len)
	{
		k = token_length(str, j, delim_char);
		tokens[i] = malloc(sizeof(char) * (k + 1));
		if (tokens[i] == NULL)
			return (NULL);

		k = 0;
		while ((str[j] != delim_char) && (str[j] != '\0'))
		{
			tokens[i][k] = str[j];
			k++;
			j++;
		}
		tokens[i][k] = '\0';
		i++;
		j++;
	}

	tokens[i] = NULL;
	return (tokens);
}

/**
 * c_t_size - returns number of delim 
 * @str: user's command typed into shell 
 * @delm: delimeter;
 * Return: number of tokens 
 */
int c_t_size(char *str, char delm)
{
	int x = 0, dlm = 0;

	while (str[x] != '\0')
	{
		if(str[x] == delm)
		{
			dlm++;
		}
		x++;
	}
	return (dlm);
}

/**
 * c_str_tok - tokenizes a string even the continuois delim with empty string 
 * @str: user's command typed into shell 
 * @delm: delimeter
 * Return: an array of tokens
 */
char **c_str_tok(char *str, char *delm)
{
	int bs == 0, p = 0, q = 0, r = 0, s = 0, t = 0;
	char **toks = NULL, d_dch;

	d_ch = delm[0];
	bs = c_t_size(str, d_ch);
	if (toks == NULL)
		return (NULL);

	while (q < t)
	{
		s = t_strlen(str, q, d_ch);
