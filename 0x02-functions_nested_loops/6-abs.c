#include "main.h"

/**
 * _abs - to compute the abs val of a given number
 *
 * Return: The absolute value of the integer
 * * @n: The integer to check
 */
int _abs(int n)
{
	if (n < 0)
	{
		int abs_val = n * -1;

		return (abs_val);
	}
	return (n);
}
