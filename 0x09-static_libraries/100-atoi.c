#include "main.h"
/**
 * _atoi - convert a string to an integer.
 *
 * @s: string to be converted into an integer.
 *
 * Return: the int converted from the string.
 */
int _atoi(char *s)
{
	int j, k, l, leng, m, digit;

	j = 0, k = 0, l = 0, leng = 0, m = 0, digit = 0;

	while (s[leng] != '\0')
		leng++;

	while (j < leng && m == 0)
	{
		if (s[j] == '-')
			++k;

		if (s[j] >= '0' && s[j] <= '9')
		{
			digit = s[j] - '0';
			if (k % 2)
				digit = -digit;
			l = l * 10 + digit;
			m = 1;
			if (s[j + 1] < '0' || s[j + 1] > '9')
				break;
			m = 0;
		}
		j++;
	}

	if (m == 0)
		return (0);

	return (l);
}
