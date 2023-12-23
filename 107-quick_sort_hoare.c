#include "sort.h"

void qsort_it(int *array, int low, int high, size_t size);
void swap_it(int *a, int *b);
int part_it(int *array, int low, int high, size_t size);
/**
 * quick_sort_hoare - Quick Sort Algorithme using hoare part_it
 * @array: Array to sort
 * @size: Size of The Array
 * Return: Sorted Array (void)
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	qsort_it(array, 0, size - 1, size);
}

/**
 * part_it - part_it an array and using piv
 * @array: Array
 * @low: int
 * @high: int
 * @size: size of array (size_t)
 * Return: index of pivote (int)
 */
int part_it(int *array, int low, int high, size_t size)
{
	int piv = array[high];
	int i = low, j = high;

	while (1)
	{
		while (array[i] < piv)
			i++;
		while (array[j] > piv)
			j--;

		if (i < j)
		{
			swap_it(&array[i], &array[j]);
			print_array(array, size);
			i++;
			j--;
		}
		else
		{
			if (i != j)
				return (j);
			return (j - 1);
		}
	}
}
/**
 * qsort_it - Sorting Recursively an Array
 * @array: Array to be sorted
 * @low: The lowest value of the array
 * @high: highest value of the array
 * @size: Size of The Array
 * Return: void
 */
void qsort_it(int *array, int low, int high, size_t size)
{
	int i;

	if (low < high)
	{
		i = part_it(array, low, high, size);
		if (i > low)
			qsort_it(array, low, i, size);
		qsort_it(array, i + 1, high, size);
	}
}
/**
 * swap_it - swap_it two int
 * @a: int
 * @b: int
 * Return: (void) Swaped int
 */
void swap_it(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


