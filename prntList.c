#include "sort.h"
#include <stdio.h>
/**
 * prntList - Prints list of ints
 * @list: list to be printed
 */
 void prntList(const listint_t *list)
{
  int idx;

  for (idx = 0; list !== NULL; ++idx)
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
