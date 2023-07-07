#include "main.h"

/**
 * print_to_98 - to print all natural numbers from a given number n up to 98
 *
 * @n: the number passed to the function
 */
void print_to_98(int n)
{
	int j, k;

	if (n <= 98)
	{
		for (j = n; j <= 98; j++)
		{
			if (j != 98)
				printf("%d, ", j);
			else if (j == 98)
				printf("%d\n", j);
		}
	} else if (n >= 98)
	{
		for (k = n; k >= 98; k--)
		{
			if (k != 98)
				printf("%d, ", k);
			else if (k == 98)
				printf("%d\n", k);
		}
	}
}
