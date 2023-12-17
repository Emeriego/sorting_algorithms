#include "sort.h"

/**
 * selection_sort - Implementation of selection Sort Algrithme
 * @array: Array to sort type int *
 * @size: The Size of The Given Array
 *
 * Return: (Void) Sorted Array
 */
void selection_sort(int *array, size_t size)
{
	int i;
	int min, tmp;

	for (i = 0; i < (int)size; i++)
	{
		min = locate_min(array, i, size);
		if (min != -1)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
