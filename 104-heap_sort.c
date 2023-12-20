#include "sort.h"
/**
* heap_sort - Implements heap sort algo
* @array: array to be sorted
* @size: Size of array
*/

void heap_sort(int *array, size_t size)
{
	int i, tp;
	
	i = size / 2 - 1;
	if (!array || size < 2)
		return;
	while (i >= 0)
	{
		stupif(array, size, i, size);
		i--;
	}
	for (i = size - 1; i >= 0; i--)
	{
		tp = array[0];
		array[0] = array[i];
		array[i] = tp;
		if (i > 0)
			print_array(array, size);
		stupif(array, i, 0, size);
	}

}
