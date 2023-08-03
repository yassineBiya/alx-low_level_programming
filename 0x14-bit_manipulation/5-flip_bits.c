#include "main.h"
/**
 * flip_bits - returns the number of bits you would need to flip to
 * get from one number to another.
 *
 * @n: first integer.
 * @m: second integer.
 *
 * Return: number of bits to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, flipped_nbr = 0;
	unsigned long int tmp;
	unsigned long int _xor_ = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		tmp = _xor_ >> i;
		if (tmp & 1)
			flipped_nbr++;
	}

	return (flipped_nbr);
	}
