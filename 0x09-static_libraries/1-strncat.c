#include "main.h"
/**
 * _strncat - concatenate two strings
 * to use at most n bytes from src
 * src does not need to be null-terminated if it contains n or more bytes
 *
 * @dest: string strat
 * @src: string added
 * @n: nbre of added bytes
 *
 * Return: pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (j < n && src[j] != '\0')
	{
	dest[i] = src[j];
	i++;
	j++;
	}
	dest[i] = '\0';
	return (dest);
}
