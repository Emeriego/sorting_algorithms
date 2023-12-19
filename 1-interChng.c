#include "sort.h"
/**
 * interChng - interChng two items in a list
 * @head: head param.
 * @a: node
 * @b: node
 */
void interChng(listint_t *a, listint_t *b, listint_t **head)
{
	listint_t *node_a = NULL, *node_b = NULL;

	if (a == NULL || b == NULL)
		return;
	node_a = a->prev;
	node_b = b->next;
	if (node_a)
		node_a->next = b;
	if (node_b)
		node_b->prev = a;
	a->next = node_b;
	a->prev = b;
	b->next = a;
	b->prev = node_a;
	if (node_a == NULL)
		*head = b;
}
