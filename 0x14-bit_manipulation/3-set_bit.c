#include "main.h"
/**
 * set_bit - sets a bit at a given index to 1 .
 *
 * @n: pointer to integer.
 * @index: bit's index to set to 1 .
 *
 * Return: 1 if it worked, or -1 if error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (*n | (1UL << index));
	return (1);
}
