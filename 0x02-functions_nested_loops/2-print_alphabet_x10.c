#include "main.h"

/**
 * print_alphabet_x10 - prints the alphabet 10 times in lowercase,
 * followed by a new line
 *
 */
void print_alphabet_x10(void)
{
	char alpha;
	int i;

	i = 0;

	while (i < 10)
	{
		ch = 'a';
		while (alpha <= 'z')
		{
			_putchar(alpha);
			alpha++;
		}
		_putchar('\n');
		i++;
	}
}
