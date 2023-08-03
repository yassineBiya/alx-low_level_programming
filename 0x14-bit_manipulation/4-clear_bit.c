#include "main.h"
/**
 * clear_bit -  sets the value of a bit to 0 at a given index.
 *
 * @n: pointer to integer.
 * @index: bit's index to set to 0.
 *
 * Return: 1 if it worked, or -1 if error.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (*n & ~(1UL << index));
	return (1);
}
