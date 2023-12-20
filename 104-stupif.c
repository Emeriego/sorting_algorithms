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
		prntArray(array, size);
		stupif(array, heap, lar, size);
	}
}
