#include "lists.h"
/**
 * reverse_listint - reverses a listint_t linked list.
 *
 * @head: head.
 *
 * Return: a pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *pr = NULL;
	listint_t *next = NULL;

	while (*head != NULL)
	{
		next = (*head)->next;
		(*head)->next = pr;
		pr = *head;
		*head = next;
	}

	*head = pr;

	return (*head);
}
