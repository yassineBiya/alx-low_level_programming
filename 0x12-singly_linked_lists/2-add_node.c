#include "lists.h"

/**
 * add_node - adds node pointing at head of list_t.
 *
 * @head: head of LLS.
 * @str: string.
 *
 * Return: the address of the new element, or NULL if it failed.
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *node_add = malloc(sizeof(list_t));
	unsigned int len2 = 0;

	if (!node_add)
	{
		free(node_add);
		return (NULL);
	}
	node_add->str = strdup(str);

	while (str[len2] != '\0')
	{
		len2++;
	}
	node_add->len = len2;

	if (*head)
		node_add->next = *head;
	else
		node_add->next = NULL;

	*head = node_add;
	return (*head);
}
