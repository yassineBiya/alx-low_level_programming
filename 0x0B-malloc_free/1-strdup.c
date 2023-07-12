#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * _strdup - copies str into a new space in memo
 *
 * @str: char
 *
 * Return: 0
 */
char *_strdup(char *str)
{
	char *str2;
	int i, k = 0;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
		i++;

	str2 = malloc(sizeof(char) * (i + 1));

	if (str2 == NULL)
		return (NULL);

	for (k = 0; str[k]; k++)
		str2[k] = str[k];

	return (str2);
}
