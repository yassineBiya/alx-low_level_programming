#include <stdlib.h>
#include <stdio.h>

/**
 * main - To print the numbers base 16 in low using putchar
 * followed by newline.
 *
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	int i;

	for (i = 0; i < 16; i++)
	{
		if (i < 10)
		{
		putchar(i + '0');/*digits 0-9*/
		}
		else
		{
			putchar(i - 10 + 'a');/*letter a-f*/	
		}
	}
	putchar('\n');
	return (0);
}
