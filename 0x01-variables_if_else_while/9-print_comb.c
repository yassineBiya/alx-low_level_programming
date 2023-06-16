#include <stdlib.h>
#include <stdio.h>

/**
 * main - To print every combination of single digits using putchar
 * followed by newline.
 *
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	int i;
	
	for (i = 0; i <= 9; i++)
	{
		putchar(i + '0');
        if (i != 9)
		{
			putchar(',');
			putchar(' ');
		}
	}
	
	putchar('\n');    
	return (0);
}
