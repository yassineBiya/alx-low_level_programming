#include "main.h"
/**
 * print_binary - prints  the binary representation of a number.
 *
 * @n: number to print in binary.
 *
 * Return: void.
 */
void print_binary(unsigned long int n)
{
	int i, bit_nbr = 0; /*track current bit & the nbr of bits printed*/
	unsigned long int tmp;

	for (i = 63; i >= 0; i--)
	{
		tmp = n >> i;

		if (tmp & 1)
		{
			_putchar('1');
			bit_nbr++;
		}
		else if (bit_nbr != NULL)
			_putchar('0');
	}
	if (bit_nbr == 0)
		_putchar('0');
}
