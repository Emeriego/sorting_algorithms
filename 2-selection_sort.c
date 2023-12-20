#include "sort.h"

/**
 * selection_sort - Selection Sort Algrithm
 * @array: Array to be sort
 * @size: size of Array
 */
void selection_sort(int *array, size_t size)
{
	int idx;
	int smaller_value, temp;

	for (idx = 0; idx < (int)size; idx++)
	{
		smaller_value = getMin(array, idx, size);
		if (smaller_value != -2)
		{
			temp = array[idx];
			array[idx] = array[smaller_value];
			array[smaller_value] = temp;
			print_array(array, size);
		}
	}
}
