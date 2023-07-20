#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"
#include "variadic_functions.h"
/**
 * print_strings - prints strings, followed by a new line.
 *
 * @separator: the string to be printed between the strings.
 * @n: the number of strings passed to the function.
 * @...: nbr of strings to be printed.
 *
 * Description: If separator is NULL, then do not print.
 * If one of the strings is NULL,  print (nil) instead.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list strs;
	char *str;
	unsigned int i;

	va_start(strs, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(strs, char *);

		if (str == NULL)
			printf("(nil)");
		else
			printf("%s", str);

		if (i != (n - 1) && separator != NULL)
			printf("%s", separator);
	}

	printf("\n");

	va_end(strs);
}

