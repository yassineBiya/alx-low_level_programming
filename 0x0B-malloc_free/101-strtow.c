#include <stdlib.h>
#include "main.h"
/**
 * wording - counts how many words in input string
 *
 * @s: string input
 *
 * Return: nbr of words
 */
int wording(char *s)
{
	int count, i, xw;

	count = 0;
	xw = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
			count = 0;
		else if (count == 0)
		{
			count = 1;
			xw++;
		}
	}

	return (xw);
}
/**
 * **strtow - splits a string into words.
 *
 * @str: the string to split
 *
 * Return: pointer to an array of str in Success
 * or NULL in Failure
 */
char **strtow(char *str)
{
	char **grid, *tmp;
	int j, words, s, e;
	int  k = 0, leng = 0, a = 0;

	while (*(str + leng))
		leng++;
	words = wording(str);
	if (words == 0)
		return (NULL);

	grid = (char **) malloc(sizeof(char *) * (words + 1));
	if (grid == NULL)
		return (NULL);

	for (j = 0; j <= leng; j++)
	{
		if (str[j] == ' ' || str[j] == '\0')
		{
			if (a)
			{
				e = j;
				tmp = (char *) malloc(sizeof(char) * (a + 1));
				if (tmp == NULL)
					return (NULL);
				while (s < e)
					*tmp++ = str[s++];
				*tmp = '\0';
				grid[k] = tmp - a;
				k++;
				a = 0;
			}
		}
		else if (a++ == 0)
			s = j;
	}

	grid[k] = NULL;

	return (grid);
}
