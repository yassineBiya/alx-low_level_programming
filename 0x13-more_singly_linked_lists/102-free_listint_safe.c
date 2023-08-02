#include "lists.h"
/**
 * free_listint_safe - frees a listint_t list..
 *
 * @h: head.
 *
 * Return:  the size of the list that was free’d.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t node_nbr = 0;
	listint_t *current, *tmp;

	current = *h;
	*h = NULL;

	while (current != NULL)
	{
		node_nbr++;
		tmp = current->next;
		free(current);
		current = tmp;
	}

	return (node_nbr);
}
