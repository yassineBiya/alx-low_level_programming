#include <stdlib.h>
#include <stdio.h>

/**
 * main - To print the alphabets in lower than upper -case
 * followed by newline.
 *
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	char alpha[52] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i;

	for (i = 0; i < 52; i++)
	{
		putchar(alpha[i]);
	}
	putchar('\n');
	return (0);
}
