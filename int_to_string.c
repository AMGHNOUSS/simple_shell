#include "shell.h"

/**
 * numlen - counts number of 0s in a tens power number
 * @n: number
 * Return: returns count of digits
 */
int numlen(int n)
{
	int cnt = 0, x = n;

	while (x > 9 || x < -9)
	{
		x /= 10;
		cnt++;
	}
	return (cnt);
}
/**
 * int_to_string - turns an int into a string
 * @number: int
 * Return: returns the int as a string. returns NULL if failed
 */

char *int_to_string(int number)
{
	int q, r, s = 0, t = 0, x;
	char *res;

	q = number;
	r = 1;

	if (number < 0)
		t = 1;
	res = malloc(sizeof(char) * (numlen(q) + 2 + t));
	if (res == NULL)
		return (NULL);
	if (number < 0)
	{
		res[s] = '-';
		s++;
	}
	for (x = 0; q > 9 || q < -9; x++)
	{
		q /= 10;
		r *= 10;
	}
	for (q = number; x >= 0; x--)
	{
		if (q < 0)
		{
			res[s] = (q / r) * -1 + '0';
			s++;
		}
		else
		{
			res[s] = (q / r) + '0';
			s++;
		}
		q %= r;
		r /= 10;
	}
	res[s] = '\0';
	return (res);
}
