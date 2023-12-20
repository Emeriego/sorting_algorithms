#include "sort.h"
/**
* stupif - recurrssive heap
* @array: Array to be sorted
* @heap: size of heap data
* @idx: index
* @size: size of array
*/
void stupif(int *array, int heap, int idx, int size)
{
	int lar = idx;
	int left;
	int right, tud;

	left = 2 * idx + 1;
	right = 2 * idx + 2;
	if (left < heap && array[left] > array[lar])
	{
		lar = left;
	}
	if (right < heap && array[right] > array[lar])
		lar = right;
	if (lar != idx)
	{
		tud = array[idx];
		array[idx] = array[lar];
		array[lar] = tud;
		print_array(array, size);
		stupif(array, heap, lar, size);
	}
}

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
