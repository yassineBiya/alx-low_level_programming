#include "main.h"
/**
 * _stringReverse - reverses an array
 *
 * @n: integer
 *
 * Return: 0
 */
void _stringReverse(char *n)
{
	int i = 0;
	int j = 0;
	char temp;

	while (*(n + i) != '\0')
	{
		i++;
	}
	i--;

	for (j = 0; j < i; j++, i--)
	{
		temp = *(n + j);
		*(n + j) = *(n + i);
		*(n + i) = temp;
	}
}
/**
 * infinite_add - adds two numbers.
 *
 * @n1: First number to add
 * @n2: Second number to add
 * @r: pointer to buffer
 * @size_r: buffer size
 *
 * Return: pointer to function call
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int roverflow = 0, i = 0, j = 0, digits = 0;
	int val1 = 0, val2 = 0, temp_total = 0;

	while (*(n1 + i) != '\0')
		i++;
	while (*(n2 + j) != '\0')
		j++;
	i--;
	j--;
	if (j >= size_r || i >= size_r)
		return (0);
	while (j >= 0 || i >= 0 || roverflow == 1)
	{
		if (i < 0)
			val1 = 0;
		else
			val1 = *(n1 + i) - '0';
		if (j < 0)
			val2 = 0;
		else
			val2 = *(n2 + j) - '0';
		temp_total = val1 + val2 + roverflow;
		if (temp_total >= 10)
			roverflow = 1;
		else
			roverflow = 0;
		if (digits >= (size_r - 1))
			return (0);
		*(r + digits) = (temp_total % 10) + '0';
		digits++;
		j--;
		i--;
	}
	if (digits == size_r)
		return (0);
	*(r + digits) = '\0';
	_stringReverse(r);
	return (r);
}
