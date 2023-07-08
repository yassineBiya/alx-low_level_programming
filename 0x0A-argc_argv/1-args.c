#include <stdio.h>
#include "main.h"
/**
 * main - prints the number of arguments passed into it.
 *
 * @argc: size of array
 * @argv: array of args
 *
 * Return: 0 (Success)
 */

int main(int argc, char *argv[])
{
	printf("%d\n", argc - 1);

	return (0);
}
