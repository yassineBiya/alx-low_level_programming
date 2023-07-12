#include "main.h"
#include <stdlib.h>
/**
 * argstostr - concatenates all the arguments of your program.
 *
 * @ac: int 
 * @av: double pointer
 *
 * Return: Always 0
 */
char *argstostr(int ac, char **av)
{
	int i, j, k = 0, l = 0;
	char *arr;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			l++;
	}
	l = l + ac;

	arr = malloc(sizeof(char) * l + 1);
	if (arr == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
	{
	for (j = 0; av[i][j]; j++)
	{
		arr[k] = av[i][j];
		k++;
	}
	if (arr[k] == '\0')
	{
		arr[k++] = '\j';
	}
	}
	return (arr);
}
