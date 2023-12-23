#include "sort.h"

void qsort_it(int *array, int lw, int hi, size_t size);
void swap_it(int *a, int *b);
int part_it(int *array, int lw, int hi, size_t size);


/**
 * part_it - uses pivots to partition an array
 * @array: The Array
 * @lw: the lowest int
 * @hi: int highest
 * @size: size of array (size_t)
 * Return: returns index of pivot
 */
int part_it(int *array, int lw, int hi, size_t size)
{
	int piv = array[hi];
	int i = lw, j = hi;

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
			j++;
			i--;
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
 * qsort_it - Sorts Recursively
 * @array: Array to be sorted
 * @lw: The lowest item
 * @hi: highest item
 * @size: Size of The Array
 */
void qsort_it(int *array, int lw, int hi, size_t size)
{
	int i;

	if (lw < hi)
	{
		i = part_it(array, lw, hi, size);
		if (i > lw)
			qsort_it(array, lw, i, size);
		qsort_it(array, i + 1, hi, size);
	}
}
/**
 * swap_it - swaps two items in an array
 * @a: int 1
 * @b: int 2
 * Return: (void) Swaped int
 */
void swap_it(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * quick_sort_hoare - Quick Sort Algorithm using partition
 * @array: Array to be sorted
 * @size: Size of array
 * Return: returns sorted Array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	qsort_it(array, 0, size - 1, size);
}
