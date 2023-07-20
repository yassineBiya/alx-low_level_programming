#include "3-calc.h"
#include <stdio.h>
int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);
/**
 * op_add - sum of two numbers.
 *
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The sum.
 */
int op_add(int a, int b)
{
	return (a + b);
}
/**
 * op_sub -difference of two numbers.
 *
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The difference.
 */
int op_sub(int a, int b)
{
	return (a - b);
}
/**
 * op_mul - roduct of two numbers.
 *
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The product.
 */
int op_mul(int a, int b)
{
	return (a * b);
}
/**
 * op_div - division of two numbers.
 *
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The quotient.
 */
int op_div(int a, int b)
{
	return (a / b);
}
/**
 * op_mod - the remainder of the division of two numbers.
 *
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The remainder.
 */
int op_mod(int a, int b)
{
	return (a % b);
}
