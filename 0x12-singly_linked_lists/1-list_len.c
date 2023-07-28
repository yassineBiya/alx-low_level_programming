#include "lists.h"

/**
 * list_len - number of elements in an SLL.
 *
 * @h: SLL.
 *
 * Return: nbre of nodes.
 */

size_t list_len(const list_t *h)
{

unsigned int n = 0;

	while (h)
	{
		n++;
		h = h->next;
	}
	return (n);
}
