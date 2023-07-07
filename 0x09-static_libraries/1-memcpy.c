#include "main.h"
/**
 *_memcpy - copies memory area.
 *
 *@dest: dest memory area
 *@src: src memory area
 *@n: number of bytes to be copied
 *
 *Return: a pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int j = 0;
	int i = n;

	for (; j < i; j++)
	{
		dest[j] = src[j];
		n--;
	}
	return (dest);
}
