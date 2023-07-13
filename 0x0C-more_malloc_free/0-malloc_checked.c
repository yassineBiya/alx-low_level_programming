#include <stdlib.h>
#include "main.h"
/**
 * *malloc_checked - allocates memory using malloc.
 *
 * @b: nbre of b to allocate.
 *
 * Return: a pointer to the allocated memory.
 */
void *malloc_checked(unsigned int b)
{
	void *ptr; /* To allocate memory of any data type.*/

	ptr = malloc(b);

	if (ptr == NULL)
		exit(98);

	return (ptr);
}
