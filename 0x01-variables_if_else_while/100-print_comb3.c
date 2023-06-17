#include <stdlib.h>
#include <stdio.h>

/**
 * main - To print every combination of 2 digits using putchar
 * followed by newline.
 *
 *
 * Return: Always 0 (success)
*/
int main(void)
{
	int i, j;

	for (i = 48; i <= 56; i++)
	{
		for (j = 49; j <= 57; j++)
		{
			if (j > i)
			{
				putchar(i);
				putchar(j);
				if (i != 56 || j != 57)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
