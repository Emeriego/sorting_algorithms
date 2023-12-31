#include "sort.h"
/**
 * getListLen - gets length of list
 * @list: head of list
 * Return: length
 */
size_t getListLen(listint_t *list)
{
	size_t len = 0;

	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

/**
 * swapNodes - Swaps nodes at pointer ptr with the next node
 * @list: head of list
 * @ptr: pointer to node
 */
void swapNodes(listint_t **list, listint_t **ptr)
{
	listint_t *one, *two, *three, *four;

	one = (*ptr)->prev;
	two = *ptr;
	three = (*ptr)->next;
	four = (*ptr)->next->next;
	two->next = four;
	if (four)
		four->prev = two;
	three->next = two;
	three->prev = two->prev;
	if (one)
		one->next = three;
	else
		*list = three;
	two->prev = three;
	*ptr = three;
}

/**
 *  cocktail_sort_list - Sorts a doubly linked list with Cocktail
 * @list: pointer to the list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *ptr;
	int sorted = 0;

	if (list == NULL || *list == NULL || getListLen(*list) < 2)
	{
		return;
	}
	ptr = *list;
	while (!sorted)
	{
		sorted = 1;
		while (ptr->next != NULL)
		{
			if (ptr->n > ptr->next->n)
			{
				sorted = 0;
				swapNodes(list, &ptr);
				print_list(*list);
			}
			else
			{
				ptr = ptr->next;
			}
		}
		if (sorted)
			break;
		ptr = ptr->prev;
		while (ptr->prev)
		{
			if (ptr->n < ptr->prev->n)
			{
				sorted = 0;
				ptr = ptr->prev;
				swapNodes(list, &ptr);
				print_list(*list);
			}
			else
				ptr = ptr->prev;
		}
	}
}
