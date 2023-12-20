#include "sort.h"
/**
 * getMin - Locatin the min From Current index in the array
 * @array: The Array to be Searched
 * @index: Starting Index of The Search
 * @size: The Size of The Array
 * Return: (int) index of min if found or
 * same given index if index is the min
 */

int getMin(int *array, int index, size_t size)
{
	int min, idx_min, idx;

	min = array[index];
	idx_min = index;
	for (idx = index; idx < (int)size; idx++)
	{
		if (array[idx] < min)
		{
			min = array[idx];
			idx_min = idx;
		}
	}
	if (idx_min == index)
	{
		return (-2);
	}
	return (idx_min);
}

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
