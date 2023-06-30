#include "main.h"
#include <stdio.h>

/**
 * rot13 - encodes a string using rot13.
 *
 * @s: input string
 *
 * Return: pointer to new encoded string
 */

char *rot13(char *s)
{
	int i;
	int j;
	char arr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (s[i] == arr[j])
			{
				s[i] = rot[j];
				break;
			}
		}
	}
	return (s);
}
