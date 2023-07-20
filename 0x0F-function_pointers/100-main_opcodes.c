#include <stdio.h>
#include <stdlib.h>
/**
 * main - pints opcodes.
 *
 * @argc: nbr of args.
 * @argv: array of args.
 *
 * Return: 0 (success).
 */
int main(int argc, char *argv[])
{
	char *opco = (char *) main;
	int i, bytes_nbr;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	bytes_nbr = atoi(argv[1]);

	if (bytes_nbr < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (i = 0; i < bytes_nbr; i++)
	{
		printf("%02x", opco[i] & 0xFF);
		if (i != bytes_nbr - 1)
			printf(" ");
	}

	printf("\n");
	return (0);
}
