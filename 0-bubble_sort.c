#include "sort.h"
/**
 *bubble_sort - sorts an array of integers in ascending orde
 *@array: the array to be sort
 *@size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int c;
	size_t j, idx;

	if (size < 1)
		return;
	for (idx = 0; idx < size - 1; idx++)
	{
		for (j = 0; j < size - idx - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				c = array[j];
				array[j] = array[j + 1];
				array[j + 1] = c;
				print_array(array, size);
			}
		}
	}
}

