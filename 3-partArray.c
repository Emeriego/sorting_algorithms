#include "sort.h"
/**
 * partArray - Partitions an array
 * @array: Array to be worked on
 * @low: int
 * @high: int
 * @size: size of array (size_t)
 * Return: index of pivote (int)
 */
int partArray(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int ct, y;

	ct = low - 1;
	for (y = low; y <= high; y++)
	{
		if (array[y] <= pivot)
		{
			ct++;
			if (ct != y)
			{
				exchng(&array[ct], &array[y]);
				prntArray(array, size);
			}
		}
	}
	return (ct);
}
