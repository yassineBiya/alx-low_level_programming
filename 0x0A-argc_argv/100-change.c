#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - prints the minimum number of coins to
 * make change for an amount of money.
 *
 * @argc: size of array
 * @argv: array of args
 *
 * Return: 0 (Success), 1 (Failure)
 */
int main(int argc, char *argv[])
{
	int nbre, i, change;
	int coins[] = {25, 10, 5, 2, 1};

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	nbre = atoi(argv[1]);
	change = 0;

	if (nbre < 0)
	{
		printf("0\n");
		return (0);
	}

	for (i = 0; i < 5 && nbre >= 0; i++)
	{
		while (nbre >= coins[i])
		{
			change++;
			nbre -= coins[i];
		}
	}

	printf("%d\n", change);
	return (0);
}
