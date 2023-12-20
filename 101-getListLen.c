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
