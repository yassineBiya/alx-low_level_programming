#include "main.h"

/**
 * jack_bauer - to print every minute of the day from 00:00 2 23:59
 */

void jack_bauer(void)
{
	int m, n;

	m = 0;

	while (m < 24)
	{
		n = 0;
		while (n < 60)
		{
			_putchar((m / 10) + '0');
			_putchar((m % 10) + '0');
			_putchar(':');
			_putchar((n / 10) + '0');
			_putchar((n % 10) + '0');
			_putchar('\n');
			n++;
		}
		m++;
	}
}
