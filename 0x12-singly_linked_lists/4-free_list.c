#include "lists.h"

/**
 * free_list - frees a list_t list.
 *
 * @head: head of the SLL.
 *
 * Return: void.
 */
void free_list(list_t *head)
{
	list_t *temp;

	temp = head;
	while (temp)
	{
		free(temp->str);
		free(temp);
		temp = temp->next;
	}
}
