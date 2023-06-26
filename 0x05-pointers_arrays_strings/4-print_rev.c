#include "main.h"
/**
 * print_rev - prints a string, in reverse, followed by a new line.
 *
 * @s: string
 * return: 0
 */
void print_rev(char *s)
{
	int leng = 0;
	int m;

	while (*s != '\0')
	{
		leng++;
		s++;
	}

	s--;

	for (m = leng; m > 0; m--)
	{
		_putchar(*s);
		s--;
	}

	_putchar('\n');
}
