#include "sort.h"

/**
 * interSwap - interSwap two items in a list
 * @head: head param.
 * @a: node
 * @b: node
 */
void interSwap(listint_t *a, listint_t *b, listint_t **head)
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
/**
 * insertion_sort_list  - insertion_sort_list sorts using insertion
 * @list: doubly liked list
 */
void insertion_sort_list(listint_t **list)
{
	int dat;
	listint_t *head;
	listint_t *prev;

	if (list == NULL || (*list)->next == NULL || (*list) == NULL)
	{
		return;
	}
	head = *list;
	while (head != NULL)
	{
		prev = head->prev;
		dat = head->n;
		while (prev && prev->n > dat)
		{
			interSwap(prev, head, list);
			print_list(*list);
			prev = head->prev;
		}
		head = head->next;
	}
}
