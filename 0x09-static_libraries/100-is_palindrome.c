#include "main.h"
int check_palind(char *s, int i, int leng);
int _strlen_recursion(char *s);
/**
 * is_palindrome - checks if a string is a palindrome.
 *
 * @s: string to reverse
 *
 * Return: 1 if a string is a palindrome and 0 if not.
 */
int is_palindrome(char *s)
{
	if (*s == 0)
		return (1);
	return (check_palind(s, 0, _strlen_recursion(s)));
}
/**
 * _strlen_recursion - returns the length of a string.
 *
 * @s: string to compute the length
 *
 * Return: length of string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen_recursion(s + 1));
}
/**
 * check_palind - checks the characters recursively for palindrome.
 *
 * @s: string to check
 * @i: iterator
 * @leng: length of the string
 *
 * Return: 1 if palindrome and 0 if not.
 */
int check_palind(char *s, int i, int leng)
{
	if (*(s + i) != *(s + leng - 1))
		return (0);
	if (i >= leng)
		return (1);
	return (check_palind(s, i + 1, leng - 1));
}
