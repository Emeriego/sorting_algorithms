#include "sort.h"
/**
 * shell_sort -Sort an array using shell_sort algorithm
 * @array: array
 * @size: size of the array
 **/
void shell_sort(int *array, size_t size)
{
	int temp;
	unsigned int interval, idx, j;

	interval = 1;
	if (array == NULL)
		return;
	if (size < 2)
		return;
	while (interval < size / 3)
	{
		interval = interval * 3 + 1;
	}
	while (interval > 0)
	{
		for (idx = interval; idx < size; idx++)
		{
			temp = array[idx];
			j = idx;
			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = temp;
		}
		print_array(array, size);
		interval /= 3;
	}
}
