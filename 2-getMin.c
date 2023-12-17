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
	int min, idx_min;
	int i;

	min = array[index];
	idx_min = index;
	for (i = index; i < (int)size; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
			idx_min = i;
		}
	}
	if (idx_min == index)
		return (-1);
	return (idx_min);
