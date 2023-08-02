#include "lists.h"
/**
 * pop_listint - deletes the head node of a listint_t linked list.
 *
 * @head: head.
 *
 * Return: 0 if sll is empty or the head node’s data (n).
 */
int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int num;

	if (head == NULL || *head == NULL)
		return (0);

	num = (*head)->n;
	tmp = (*head)->next;
	free(*head);
	*head = tmp;

	return (num);
}
