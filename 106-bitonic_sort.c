#include "sort.h"

void mergit(int *array, int low, int count, int dir, size_t size);
void swapIt(int *lft, int *rght);
void sortit(int *array, int low, int count, int dir, size_t size);
/**
* bitonic_sort - Sorts array using bitonic algorithm
* @array: Array to sort
* @size: Size of array
*/

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sortit(array, 0, size, 1, size);
}

/**
* sortit - bitonic recursive sort
* @array: array to sort
* @low: lowest index
* @count: Count of slice
* @dir: ascending = 1, descending = 0
* @size: size of total array for printing
*/

void sortit(int *array, int low, int count, int dir, size_t size)
{
	int n;

	if (count > 1)
	{
		n = count / 2;
		printf("Merging [%d/%d] ", count, (int)size);
		if (dir == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + low, count);
		sortit(array, low, n, 1, size);
		sortit(array, low + n, n, 0, size);
		mergit(array, low, count, dir, size);
		printf("Result [%d/%d] ", count, (int)size);
		if (dir == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + low, count);
	}
}

/**
* swapIt - swaps indexes
* @lft: left of array
* @rght: right of array
*/
void swapIt(int *lft, int *rght)
{
	int tm;

	tm = *lft;
	*lft = *rght;
	*rght = tm;
}

/**
* mergit - bitonic merge
* @array: slices being merged
* @low: lowest idx
* @count: slice count
* @dir: Direction, ascending 1 descending 0
* @size: size of array for printing
*/

void mergit(int *array, int low, int count, int dir, size_t size)
{
	int i, n;

	if (count > 1)
	{
		n = count / 2;
		for (i = low; i < low + n; i++)
		{
			if (((array[i] > array[i + n]) && dir == 1) ||
			(dir == 0 && (array[i] < array[i + n])))
				swapIt(&array[i], &array[i + n]);
		}
		mergit(array, low, n, dir, size);
		mergit(array, low + n, n, dir, size);
	}
}
