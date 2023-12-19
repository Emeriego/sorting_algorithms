#include "sort.h"
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
			interChng(prev, head, list);
			prntList(*list);
			prev = head->prev;
		}
		head = head->next;
	}
}
