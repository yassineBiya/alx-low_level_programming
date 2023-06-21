#include "main.h"

/**
 * _islower - to check if a char is lowercase
 * 
 * Return: 1 if the char is lowercase, or 0 if it is not.
 */

int _islower(int char)
{
	if (char >= 'a' && char <= 'z')
		return (1);
	else
		return (0);
}
