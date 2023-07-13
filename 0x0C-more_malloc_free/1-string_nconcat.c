#include <stdlib.h>
#include "main.h"
/**
 * *string_nconcat - concatenates n bytes of a string to another string.
 *
 * @s1: first str.
 * @s2: str to add n bytes from.
 * @n: nbre of b to concatenate to s1.
 *
 * Return: pointer to the s1+n*s2.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *str;
	unsigned int i = 0, j = 0, ls1 = 0, ls2 = 0;

	while (s1 && s1[ls1])
		ls1++;
	while (s2 && s2[ls2])
		ls2++;

	if (n < ls2)
		str = malloc(sizeof(char) * (ls1 + n + 1));
	else
		str = malloc(sizeof(char) * (ls1 + ls2 + 1));

	if (!str)
		return (NULL);

	while (i < ls1)
	{
		str[i] = s1[i];
		i++;
	}

	while (n < ls2 && i < (ls1 + n))
		str[i++] = s2[j++];

	while (n >= ls2 && i < (ls1 + ls2))
		str[i++] = s2[j++];

	str[i] = '\0';

	return (str);
}
