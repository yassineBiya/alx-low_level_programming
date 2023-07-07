#include <stdio.h>

/**
 * main - to find and print the first 98 Fibonacci numbers,
 * starting with 1 and 2,
 * followed by a new line
 * The numbers should be separated by comma, followed by a space
 *
 *
 * Return: 0
 */

int main(void)
{
	unsigned long int i;
	unsigned long int before = 1, after = 2;
	unsigned long int l = 1000000000;
	unsigned long int after1, after2, before1, before2;

	printf("%lu", before);

	for (i = 1; i < 91; i++)
	{
		printf(", %lu", after);
		after = after + before;
		before = after - before;
	}

	before1 = (before / l);
	before2 = (before % l);
	after1 = (after / l);
	after2 = (after % l);

	for (i = 92; i < 99; ++i)
	{
		printf(", %lu", after1 + (after2 / l));
		printf("%lu", after2 % l);
		after1 = after1 + before1;
		before1 = after1 - before1;
		after2 = after2 + before2;
		before2 = after2 - before2;
	}
	printf("\n");
	return (0);
}
