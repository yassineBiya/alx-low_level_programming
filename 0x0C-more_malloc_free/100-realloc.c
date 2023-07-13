#include <stdlib.h>
#include "main.h"
/**
 * *_realloc - reallocates a memory block using malloc and free.
 *
 * @ptr: pointer to the memory previsouly allocated by a call to malloc.
 * @old_size: the size, in bytes, of the allocated space for ptr.
 * @new_size:  the new size, in bytes of the new memory block.
 *
 * Return: pointer to the newly allocated memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *ptr_new;
	char *ptr_old;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (!ptr)
		return (malloc(new_size));

	ptr_new = malloc(new_size);
	if (!ptr_new)
		return (NULL);

	ptr_old = ptr;

	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			ptr_new[i] = ptr_old[i];
	}

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			ptr_new[i] = ptr_old[i];
	}

	free(ptr);
	return (ptr_new);
}
