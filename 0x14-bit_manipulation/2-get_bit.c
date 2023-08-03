#include "main.h"
/**
 * get_bit -  returns the value of a bit at a given index.
 *
 * @n: the integer to process.
 * @index: bit's index.
 *
 * Return: value of the bit.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int value_bit;

	if (index > 63)
		return (-1);

	value_bit = (n >> index) & 1;

	return (value_bit);
}
