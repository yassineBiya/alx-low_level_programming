#include "lists.h"
#include <stdio.h>
size_t loop_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);
/**
 * print_listint_safe -  prints a listint_t linked list.
 *
 * @head: head.
 *
 * Return: the number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nd_nbr, idx = 0;

	nd_nbr = loop_listint_len(head);

	if (nd_nbr == 0)
	{
		for (; head != NULL; nd_nbr++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (idx = 0; idx < nd_nbr; idx++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (nd_nbr);
}
/**
 * loop_listint_len - Counts the nbre of unique nodes.
 *
 * @head: head.
 *
 * Return: nbre of nodes in sll.
 */
size_t loop_listint_len(const listint_t *head)
{
	const listint_t *lp1, *lp2;
	size_t nd_nbr = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	lp1 = head->next;
	lp2 = (head->next)->next;

	while (lp2)
	{
		if (lp1 == lp2)
		{
			lp1 = head;
			while (lp1 != lp2)
			{
				nd_nbr++;
				lp1 = lp1->next;
				lp2 = lp2->next;
			}

			lp1 = lp1->next;
			while (lp1 != lp2)
			{
				nd_nbr++;
				lp1 = lp1->next;
			}

			return (nd_nbr);
		}

		lp1 = lp1->next;
		lp2 = (lp2->next)->next;
	}

	return (0);
}
