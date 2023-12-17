#include "sort.h"
/**
 * interChng - interChng 2 element in an list
 * @head: head of list
 * @a: node
 * @b: node
 */
void interChng(listint_t *a, listint_t *b, listint_t **head)
{
	listint_t *aux1 = NULL, *aux2 = NULL;

	if (a == NULL || b == NULL)
		return;
	aux1 = a->prev;
	aux2 = b->next;
	/* if nodes are adjacent*/
	if (aux1)
		aux1->next = b;
	if (aux2)
		aux2->prev = a;
	a->next = aux2;
	a->prev = b;
	b->next = a;
	b->prev = aux1;
	if (aux1 == NULL)
		*head = b;
}
