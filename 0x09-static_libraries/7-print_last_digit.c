#include "main.h"

/**
 * print_last_digit - to print the last digit of a given number
 *
 * Return: value of the last digit
 * @n: the variable of which the last digit will be printed
 */
int print_last_digit(int n)
{
	int m;

	if (n < 0)
	n = n * -1;

	m = n % 10;

	if (m < 0)
		m = m * -1;

	_putchar(m + '0');

	return (m);
}
