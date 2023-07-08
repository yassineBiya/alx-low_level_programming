#include <stdio.h>
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
/**
 * main - multiplies two numbers
 *
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 (Success), 1 (Failure)
 */
int main(int argc, char *argv[])
{
	int mul, nbr1, nbr2;

	if (argc < 3 || argc > 3)
	{
		printf("Error\n");
		return (1);
	}

	nbr1 = _atoi(argv[1]);
	nbr2 = _atoi(argv[2]);
	mul = nbr1 * nbr2;

	printf("%d\n", mul);

	return (0);
}
