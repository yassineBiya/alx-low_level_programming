#include "lists.h"

/**
 * add_node_end - adds a node at SLL end.
 *
 * @head: head of SLL.
 * @str: string to add in node .
 *
 * Return: the address of the added node, or NULL if it failed.
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *node_add = malloc(sizeof(list_t)), *temp;
	size_t len2 = 0;

	if (!node_add)
		return (NULL);

	node_add->str = strdup(str);

	while (str[len2] != '\0')
	{
		len2++;
	}
	node_add->len = len2;
	node_add->next = NULL;
	temp = *head;

	if (!temp)
	{
		*head = node_add;
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = node_add;
	}

	return (*head);
}
