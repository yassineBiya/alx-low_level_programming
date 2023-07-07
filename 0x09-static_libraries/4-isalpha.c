#include "main.h"

/**
 * _isalpha - checks for alphabetic character
 * Return: 1 if ch is a letter, 0 otherwise
 * @ch: the variable to be checked
 */
int _isalpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}
