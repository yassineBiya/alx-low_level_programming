#include "main.h"
/**
 * _memset - fills a block of memory with a constant byte.
 *
 * @s: pointer to the the memory area
 * @b: the constant byte
 * @n: number of bytes to be filled
 *
 * Return: a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
