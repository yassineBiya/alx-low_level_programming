#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - program that generates random valid passwords
 * for the program 101-crackme.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int pswd[100], i, sum = 0, n;

	srand(time(NULL));

	for (i = 0; i < 100; i++)
	{
		pswd[i] = rand() % 78;
		sum += (pswd[i] + '0');
		putchar(pswd[i] + '0');
		if ((2772 - sum) - '0' < 78)
		{
			n = 2772 - sum - '0';
			sum += n;
			putchar(n + '0');
			break;
		}
	}

	return (0);
}
