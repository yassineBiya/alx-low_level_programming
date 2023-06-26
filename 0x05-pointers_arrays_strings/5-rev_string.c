#include "main.h"
/**
 * rev_string - reverses a string.
 *
 * @s: Input string
 * Return: String in reverse
 */
void rev_string(char *s)
{
	char r = s[0];
	int count = 0;
	int m;

	while (s[count] != '\0')
	count++;
 
	for (m = 0; m < count; m++)
	{
		count--;
		r = s[m];
		s[m] = s[count];
		s[count] = r;
	}
}
