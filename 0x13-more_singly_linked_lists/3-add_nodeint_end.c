#include "lists.h"
/**
 * add_nodeint_end -  adds a new node at the end of a listint_t list.
 *
 * @head: head.
 * @n: n coordinate.
 *
 * Return: address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *node_add;
	listint_t *tmp = *head;

	node_add = malloc(sizeof(listint_t));
	if (node_add == NULL)
		return (NULL);

	node_add->n = n;
	node_add->next = NULL;

	if (*head == NULL)
	{
		*head = node_add;
		return (node_add);
	}

	while (tmp->next)
		tmp = tmp->next;

	tmp->next = node_add;

	return (node_add);
}
