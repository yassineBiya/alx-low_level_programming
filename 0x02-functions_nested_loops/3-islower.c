#include "main.h"

/**
 * _islower - to check if a character is lowercase
 *@ch is the variable to be checked
 * Return: 1 if the character is lowercase, or 0 if it is not
 */

int _islower(int ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (1);
	else
		return (0);
}
