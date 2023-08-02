/**
 * add_nodeint - adds a new node at the beginning of a listint_t list.
 *
 * @head: Pointer To head.
 * @n: coordinate n.
 *
 * Return: address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *node_add;

	new = malloc(sizeof(listint_t));
	if (!node_add)
		return (NULL);

	node_add->n = n;
	node_add->next = *head;
	*head = node_add;

	return (node_add);
}
