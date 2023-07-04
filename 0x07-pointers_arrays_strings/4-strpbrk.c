#include "main.h"
/**
 * _strpbrk -  searches a string for any of a set of bytes.
 *
 * @s: input string 
 * @accept: input substring to look for
 *
 * Return: a pointer to the byte in s that matches
 */
char *_strpbrk(char *s, char *accept)
{
		int j;

		while (*s)
		{
			for (j = 0; accept[j]; j++)
			{
			if (*s == accept[j])
			return (s);
			}
		s++;
		}

	return ('\0');
}
