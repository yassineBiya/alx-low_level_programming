#include <stdio.h>

/**
 * main - to find and prints the sum of the even-valued terms,
 * followed by a new line
 *
 * Return: 0
 */
int main(void)
{
	int i;
	unsigned long l, m, j, sum;

	l = 1;
	m = 2;
	sum = 0;

	for (i = 1; i <= 33; ++i)
	{
		if (l < 4000000 && (l % 2) == 0)
		{
			sum = sum + l;
		}
		j = l + m;
		l = m;
		m = j;
	}

	printf("%lu\n", sum);

	return (0);
}
