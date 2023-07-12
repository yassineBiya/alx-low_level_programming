#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid -  returns a pointer to a 2 dimensional array of integers.
 *
 * @width: width
 * @height: height
 *
 * Return: pointer to 2 dim array
 */
int **alloc_grid(int width, int height)
{
	int **arr;
	int k, l;

	if (width <= 0 || height <= 0)
		return (NULL);

	arr = malloc(sizeof(int *) * height);

	if (arr == NULL)
		return (NULL);

	for (k = 0; k < height; k++)
	{
		arr[k] = malloc(sizeof(int) * width);

		if (arr[k] == NULL)
		{
			for (; k >= 0; k--)
				free(arr[k]);

			free(arr);
			return (NULL);
		}
	}

	for (k = 0; k < height; k++)
	{
		for (l = 0; l < width; l++)
			arr[k][l] = 0;
	}

	return (arr);
}
