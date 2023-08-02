#include "lists.h"
/**
 * print_listint - prints all the elements of a listint_t list.
 *
 * @h: SLL.
 *
 * Return: number of nodes.
 */
size_t print_listint(const listint_t *h)
{
	size_t n_nodes = 0;

	while (*h)
	{
		printf("%d\n", h->n);
		n_nodes++;
		h = h->next;
	}

	return (n_nodes);
}
