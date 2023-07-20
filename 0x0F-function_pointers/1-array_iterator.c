#include "function_pointers.h"
#include <stdio.h>
/**
 * array_iterator - executes a function given as
 * a parameter on each element of an array.
 *
 * @array: array of ints.
 * @size: of type size_t, the size of the array.
 * @f: pointer to a function of int.
 *
 * Return: void.
 **/
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array && action)
		for (i = 0; i < size; i++)
			action(array[i]);
}
