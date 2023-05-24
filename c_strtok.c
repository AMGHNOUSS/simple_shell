#include "main.h"

/**
 * c_t_size - returns number of delim
 * @str: user's command typed into shell
 * @delm: delimeter ;
 * Return: number of tokens
 */
int c_t_size(char *str, char delm)
{
	int x = 0, dlm = 0;

	while (str[x] != '\0')
	{
		if (str[x] == delm)
		{
			dlm++;
		}
		x++;
	}
	return (dlm);
}


/**
 * c_str_tok - tokenizes a string even the continuous delim with empty string
 * @str: user's command typed into shell
 * @delm: delimeter
 * Return: an array of tokens
 */
char **c_str_tok(char *str, char *delm)
{
	int bs = 0, p = 0, q = 0, r = 0, s = 0, t = 0;
	char **toks = NULL, d_ch;

	d_ch = delm[0];
	bs = c_t_size(str, d_ch);
	toks = malloc(sizeof(char *) * (bs + 2));
	if (toks == NULL)
		return (NULL);

	while (str[t] != '\0')
		t++;
	while (q < t)
	{
		s = t_strlen(str, q, d_ch);
		toks[p] = malloc(sizeof(char) * (s + 1));
		if (toks[p] == NULL)
			return (NULL);
		r = 0;
		while ((str[q] != d_ch) &&
		       (str[q] != '\0'))
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
