#include <stdio.h>
#include "main.h"
/**
 * main - prints its name, followed by a new line.
 *
 * @argc: size of array
 * @argv: array of args
 *
 * Return: 0 (Success)
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);

	return (0);
}
