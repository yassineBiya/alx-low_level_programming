#include <stdlib.h>
#include <stdio.h>

/**
 * main - To print the alphabets in lowercase in reverse
 * followed by newline.
 *
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	char alpha[26] = "abcdefghijklmnopqrstuvwxyz";
	int i;

	for (i = 25; i >= 0; i--)
	{
		putchar(alpha[i]);
	}
	putchar('\n');
	return (0);
}
