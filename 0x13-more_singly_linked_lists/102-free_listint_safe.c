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
	if (*h == NULL)
	{
		return (0);
	}

	size_t size = 0;
	listint_t *current = *h;

	while (current)
	{
		size++;
		listint_t *next = current->next;

		free(current);
		current = next;
	}

	*h = NULL;
	return (size);
}
