#include "main.h"

/**
 * t_strlen - returns token's string length for mallocing
 * @str: a token
 * @pos: index position in user's command typed into shell
 * @delm: delimeter
 * Return: token length
 */
int t_strlen(char *str, int pos, char delm)
{
	int sz = 0;

	while ((str[pos] != delm) && (str[pos] != '\0'))
	{
		pos++;
		sz++;
	}
	return (sz);
}

/**
 * t_size - returns number of delim ignoring continuous delim
 * @str: user's command typed into shell
 * @delm: delimeter
 * Return: number of delims so that (num token = delims + 1)
 */
int t_size(char *str, char delm)
{
	int x = 0, dlm = 0;

	while (str[x] != '\0')
	{
		if ((str[x] == delm) && (str[x + 1] != delm))
		{
			dlm++;
		}
		if ((str[x] == delm) && (str[x + 1] == '\0'))
		{
			dlm--;
		}
		x++;
	}
	return (dlm);
}

/**
 * ignore_delm - returns a version of string without preceeding delims
 * @str: string
 * @delm: delimiter
 * Return: new string
 */
char *ignore_delm(char *str, char delm)
{
	while (*str == delm)
		str++;
	return (str);
}

/**
 * _str_tok - tokenizes a string and returns an array of tokens
 * @str: user's command typed into shell
 * @delm: delimeter
 * Return: an array of tokens
 */
char **_str_tok(char *str, char *delm)
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
