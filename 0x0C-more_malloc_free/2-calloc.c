#include <stdlib.h>
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
/**
 * *_calloc -  allocates memory for an array, using malloc.
 *
 * @nmemb: nmbre of members of the array.
 * @size: size of each member.
 *
 * Return: pointer to the allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;

	if (nmemb * size == 0)
		return (NULL);

	ptr = malloc(size * nmemb);

	if (ptr == NULL)
		return (NULL);

	_memset(ptr, 0, nmemb * size);

	return (ptr);
}
