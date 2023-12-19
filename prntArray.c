#include <stdlib.h>
#include <stdio.h>
/**
 * prntArray - Prints an array of integers
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void prntArray(const int *array, size_t size)
{
  size_t idx;
  idx = 0;
  while (array && idx < size)
  {
    if (idx > 0)
    {
      printf(", ");
    }
    printf("%d", array[idx]);
    ++idx;
    }
    printf("\n");
}
