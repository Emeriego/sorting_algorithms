#include "sort.h"
/**
 * insertion_sort_list  - insertion_sort_list
 * @list: doubly liked list
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *prev;
	int value;

	if (list == NULL || (*list)->next == NULL || (*list) == NULL)
	{
		return;
	}
	head = *list;
	while (head)
	{
		prev = head->prev;
				value = head->n;

		while (prev && prev->n > value)
		{
			swap(prev, head, list);
			print_list(*list);
			prev = head->prev;
		}
		head = head->next;
	}
}
