#include "sort.h"
#include <stdio.h>
/**
 * print_list - Prints list of ints
 * @list: list to be printed
 */
<<<<<<< HEAD:prntList.c
void prntList(const listint_t *list)
=======
 void print_list(const listint_t *list)
>>>>>>> 50a1324dd0e961a38e2c80b34892742ce41d20d3:print_list.c
{
	int idx;

	for (idx = 0; list != NULL; ++idx)
	{
		if (idx > 0)
		{
			printf(", ");
		}
		printf("%d", list->n);
		++idx;
		list = list->next;
	}
	printf("\n");
}
