#include "sort.h"
/**
 * exchng - swap two int
 * @a: int
 * @b: int
 */
void exchng(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


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
				print_array(array, size);
			}
		}
	}
	return (ct);
}

/**
 * lomuto_schem - Sorting an arr Recursively using the lomuto scheme
 * @array: To be sorted
 * @low: Lowest value of rray
 * @high: highest value of array
 * @size: Size of Array
 */
void lomuto_schem(int *array, int low, int high, size_t size)
{
	int idx;

	if (low < high)
	{
		idx = partArray(array, low, high, size);
		lomuto_schem(array, low, idx - 1, size);
		lomuto_schem(array, idx + 1, high, size);
	}
}
/**
 * quick_sort - Quick Sort Algorithme using lomuto partArray
 * @array: Array to be sorted
 * @size: Size of Array
 */
void quick_sort(int *array, size_t size)
{
	lomuto_schem(array, 0, size - 1, size);
}
