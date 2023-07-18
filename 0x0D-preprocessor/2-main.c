#include <stdio.h>
/**
 * main - prints the name of the file the prog was compiled from
 * followed by newline
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	printf("%s\n", __FILE__);
	return (0);
}
