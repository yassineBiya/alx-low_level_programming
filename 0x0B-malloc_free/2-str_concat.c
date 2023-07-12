#include "main.h"
#include <stdlib.h>
/**
 * str_concat - concatenates two strings.
 *
 * @s1: str 1
 * @s2: str 2 to concatenate
 *
 * Return: s1 and s2 or NULL if failure
 */
char *str_concat(char *s1, char *s2)
{
	char *rslt;
	int i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	i = j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	rslt = malloc(sizeof(char) * (i + j + 1));

	if (rslt == NULL)
		return (NULL);
	i = j = 0;
	while (s1[i] != '\0')
	{
		rslt[i] = s1[i];
		i++;
	}

	while (s2[j] != '\0')
	{
		rslt[i] = s2[j];
		i++, j++;
	}
	rslt[i] = '\0';
	return (rslt);
}
