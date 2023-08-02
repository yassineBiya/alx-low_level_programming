#include "lists.h"
/**
 * sum_listint - returns the sum of data (n) of a listint_t linked list.
 *
 * @head: head.
 *
 * Return: sum.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *tmp = head;

	while (tmp)
	{
		sum += tmp->n;
		tmp = tmp->next;
	}

	return (sum);
}
