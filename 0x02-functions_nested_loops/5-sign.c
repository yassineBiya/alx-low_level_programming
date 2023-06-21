#include "main.h"

/**
 * print_sign - to Print the sign of a given number
 *
 *
 * Return: 1 if positive, -1 if negative, or 0 if 0
 * @n: The variable to be checked
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n < 0)
	{
		_putchar('-');
		return (-1);
	}
	else
	{
		_putchar('0');
		return (0);
	}
}
