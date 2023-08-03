#include "main.h"
/**
 * binary_to_uint - converts a binary number to an unsigned int.
 *
 * @b: a string of 0 and 1 chars.
 *
 * Return: the converted number, or 0 .
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int int_uns = 0;

	if (!b)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		int_uns = (int_uns * 2) + (b[i] - '0');
	}

	return (int_uns);
}
