#include "main.h"
/**
 * puts_half - prints second half of a string, followed by a new line.
 *
 * If the number of characters is odd, 
 * the function should print the last n characters of the string, 
 * where n = (length_of_the_string - 1) / 2
 *
 * @str: input.
 * Return: half of input
 */
void puts_half(char *str)
{
	int i, leng, lhalf;

	leng = 0;

	for (i = 0; str[i] != '\0'; i++)
		leng++;

	lhalf = (leng / 2);

	if ((leng % 2) == 1)
		lhalf = ((leng + 1) / 2);

	for (i = lhalf; str[i] != '\0'; i++)
		_putchar(str[i]);
	_putchar('\lhalf');
}
