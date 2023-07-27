#include "lists.h"
/**
 * print_list - prints all the elements of a list_t list.
 *
 * @h: SLL.
 *
 * Return: the number of nodes.
 */

size_t print_list(const list_t *h)
{
	size_t node_nbre;

	node_nbre = 0;
	do {
		if (h->str == NULL)
			printf("[%d] %s\n", 0, "(nil)");
		else
			printf("[%d] %s\n", h->len, h->str);
		h = h->next;
		node_nbre++;
	} while (h != NULL);

	return (node_nbre);
}
