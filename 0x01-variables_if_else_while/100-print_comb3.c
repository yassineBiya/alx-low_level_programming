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
   
   for (i = 0; i <= 9; i++) 
   {
        for (j = 0; j <= 9; j++)
		{
			putchar(i + '0');
			putchar(j + '0');
            if (i != 9 || j != 9)
			{
            putchar(',');
            putchar(' ');
            }
        }
    }
    
    putchar('\n');
    return (0);

