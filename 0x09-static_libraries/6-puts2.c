#include "main.h"
/**
 * puts2 -  prints every other character of a string,
 * starting with the first character, followed by a new line.
 *
 * @str: input
 * Return: print
 */
void puts2(char *str)
{
	int leng2 = 0;
	int l = 0;
	char *leng1 = str;
	int m;

	while (*leng1 != '\0')
	{
		leng1++;
		leng2++;
	}
	l = leng2 - 1;
	for (m = 0 ; m <= l ; m++)
	{
		if (m % 2 == 0)
	{
		_putchar(str[m]);
	}
	}
	_putchar('\n');
}
