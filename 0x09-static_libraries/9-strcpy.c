#include "main.h"
/**
 * char *_strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest.
 *
 * @dest: cp destination.
 * @src: cp source.
 *
 * Return: string.
 */
char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int m = 0;

	while (*(src + l) != '\0')
	{
		l++;
	}
	for ( ; m < l ; m++)
	{
		dest[m] = src[m];
	}
	dest[l] = '\0';
	return (dest);
}
