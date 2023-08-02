#include "lists.h"
/**
 * find_listint_loop - finds the loop in a linked list.
 *
 * @head: head.
 *
 * Return:   node where the loop starts, or NULL if there is no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head;
	listint_t *fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			return (slow);
		}
	}

	return (NULL);
}
