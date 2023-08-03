#include "main.h"
/**
 * get_endianness - checks the endianness.
 *
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
	unsigned int tmp = 1;
	char *endian = (char *)&tmp;

	if (*endian)
		return (1);
	return (0);
}
