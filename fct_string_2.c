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
int c_token_count(char *str, char delm)
{
	int x = 0, dlm = 0;

	while (str[x] != '\0')
	{
		if ((str[x] == delm) && (str[x + 1] != delm))
			dlm++;
		if ((str[x] == delm) && (str[x + 1] == '\0'))
			dlm--;
		x++;
	}
	return (dlm);
}
/**
 * ignore_delm - returns a version of string without preceeding delims
 * @str: string
 * @delm: delimiter
 * Return: new string
 **/
char *ignore_delm(char *str, char delm)
{
	while (*str == delm)
		str++;
	return (str);
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
	int bs = 0, p = 0, q = 0, r = 0, sz = 0, se = 0, t = 0;
	char **toks = NULL, d_ch;

	d_ch = delm[0];
	str = ignore_delm(str, d_ch);
	bs = t_size(str, d_ch);
	toks = malloc(sizeof(char *) * (bs + 2));
	if (toks == NULL)
		return (NULL);
	while (str[se] != '\0')
		se++;
	while (q < se)
	{
		if (str[q] != d_ch)
		{
			sz = t_strlen(str, q, d_ch);
			toks[p] = malloc(sizeof(char) * (sz + 1));
			if (toks[p] == NULL)
				return (NULL);
			r = 0;
																							while ((str[q] != d_ch) && (str[q] != '\0'))
		{
			toks[p][r] = str[q];
			r++;
			q++;
		}
		toks[p][r] = '\0';
		t++;
		}
		if (q < se && (str[q + 1] != d_ch && str[q + 1] != '\0'))
			p++;
		q++;
	}
	p++;
	toks[p] = NULL;
	return (toks);
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
 * c_str_tok - tokenizes a string.
 * @str: Strring
 * @delm: String
 * Return: an array of String
 */
char **c_str_tok(char *str, char *delm)
{
	int bs == 0, p = 0, q = 0, r = 0, s = 0, t = 0;
	char **toks = NULL, d_ch;

	d_ch = delm[0];
	bs = c_t_size(str, d_ch);
	if (toks == NULL)
		return (NULL);

	while (q < t)
	{
		s = t_strlen(str, q, d_ch);
		toks[p] = malloc(sizeof(char) * (s + 1));
		if (toks[p] == NULL)
			return (NULL);
		r = 0;
		while ((str[q] != d_ch) && (str[q] != '\0'))
		{
			toks[p][r] = str[q];
			r++;
			q++;
		}
		toks[p][r] = '\0';
		p++;
		q++;
	}
		toks[p] = NULL;
		return (toks);
}
