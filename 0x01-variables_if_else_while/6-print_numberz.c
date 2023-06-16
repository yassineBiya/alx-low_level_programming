#include <stdlib.h>
#include <stdio.h>

/**
 * main - To print the numbers btwn 0 & 9 using putchar
 * followed by newline.
 *
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		putchar(i + '0');
	}
	putchar('\n');
	return (0);
}
