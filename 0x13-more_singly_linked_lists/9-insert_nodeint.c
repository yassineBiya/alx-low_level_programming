#include "lists.h"
/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 *
 * @head: head.
 * @idx: where to add new node.
 * @n: data  (n).
 *
 * Return: address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *node_add;
	listint_t *tmp = *head;

	node_add = malloc(sizeof(listint_t));
	if (!node_add || !head)
		return (NULL);

	node_add->n = n;
	node_add->next = NULL;

	if (idx == 0)
	{
		node_add->next = *head;
		*head = node_add;
		return (node_add);
	}

	for (i = 0; tmp && i < idx; i++)
	{
		if (i == idx - 1)
		{
			node_add->next = tmp->next;
			tmp->next = node_add;
			return (node_add);
		}
		else
			tmp = tmp->next;
	}

	return (NULL);
}
