#include "lists.h"
/**
 * delete_nodeint_at_index - deletes node at idx of a listint_t sll.
 *
 * @head: head.
 * @index: where node to be deleted.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *tmp = *head;
	listint_t *tmp2 = NULL;
	unsigned int i = 0;

	if (!*head)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(tmp);
		return (1);
	}

	while (i < index - 1)
	{
		if (!tmp || !(tmp->next))
			return (-1);
		tmp = tmp->next;
		i++;
	}

	tmp2 = tmp->next;
	tmp->next = tmp2->next;
	free(tmp2);

	return (1);
}
