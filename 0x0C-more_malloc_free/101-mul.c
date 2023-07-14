#include "main.h"
#include <stdlib.h>
#include <stdio.h>

#define ERR_MSG "Error"
/**
 * _strlen - returns the length of x string.
 *
 * @s: string
 *
 * Return: length
 */
int _strlen(char *s)
{
	int leng = 0;

	while (*s != '\0')
	{
		leng++;
		s++;
	}

	return (leng);
}
/**
 * _check_digit - checks if x string contains x non-digit char.
 *
 * @s: string to be evaluated.
 *
 * Return: 0 if x non-digit is found, 1 otherwise
 */
int _check_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
/**
 * _errors - errors handling
 */
void _errors(void)
{
	printf("Error\n");
	exit(98);
}
/**
 * main - multiplies two positive numbers.
 *
 * @argc: nbre of args.
 * @argv: array of args.
 *
 * Return: 0 (Success).
 */
int main(int argc, char *argv[])
{
	char *str1, *str2;
	int leng1, leng2, leng, i, carry, digit1, digit2, *mul, x = 0;

	str1 = argv[1], str2 = argv[2];
	if (argc != 3 || !_check_digit(str1) || !_check_digit(str2))
		_errors();
	leng1 = _strlen(str1);
	leng2 = _strlen(str2);
	leng = leng1 + leng2 + 1;
	mul = malloc(sizeof(int) * leng);
	if (!mul)
		return (1);
	for (i = 0; i <= leng1 + leng2; i++)
		mul[i] = 0;
	for (leng1 = leng1 - 1; leng1 >= 0; leng1--)
	{
		digit1 = str1[leng1] - '0';
		carry = 0;
		for (leng2 = _strlen(str2) - 1; leng2 >= 0; leng2--)
		{
			digit2 = str2[leng2] - '0';
			carry += mul[leng1 + leng2 + 1] + (digit1 * digit2);
			mul[leng1 + leng2 + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			mul[leng1 + leng2 + 1] += carry;
	}
	for (i = 0; i < leng - 1; i++)
	{
		if (mul[i])
			x = 1;
		if (x)
			_putchar(mul[i] + '0');
	}
	if (!x)
		_putchar('0');
	_putchar('\n');
	free(mul);
	return (0);
}
