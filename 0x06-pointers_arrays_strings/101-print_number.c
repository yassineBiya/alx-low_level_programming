#include "main.h"
/**
 * print_number - prints an integer.
 *
 * @n: integer to be printed
 *
 * Return: success
 */
void print_number(int n)
{
	unsigned int tmp;

	tmp = n;

	if (n < 0)
	{
		_putchar('-');
		tmp = -n;
	}

	if (tmp / 10 != 0)
	{
		print_number(tmp / 10);
	}
	_putchar((tmp % 10) + '0');
}
