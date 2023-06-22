#include <stdio.h>

/**
 * main - to print the numbers from 1 to 100,
 * followed by a new line
 *
 * but for multiples of 3 to print Fizz instead of the number
 * and for the multiples of 5 to print Buzz
 * and FizzBuzz for mulitples of 3 & 5
 * Return: 0
 */
int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0 && i % 5 != 0)
		{
			printf(" Fizz");
		} else if (i % 5 == 0 && i % 3 != 0)
		{
			printf(" Buzz");
		} else if (i % 3 == 0 && i % 5 == 0)
		{
			printf(" FizzBuzz");
		} else if (i == 1)
		{
			printf("%d", i);
		} else
		{
			printf(" %d", i);
		}
	}
	printf("\n");

	return (0);
}
