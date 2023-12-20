#include "sort.h"
/**
 * get_max - Get the maximum value in an array of integers.
 * @array: Array of integers.
 * @size: Size of array.
 *
 * Return: returns max int in an array.
 */
int getMax(int *array, int size)
{
	int mx, idx;

    mx = array[0];
    idx = 1;
	while (idx < size)
	{
		if (array[idx] > mx)
			mx = array[idx];
        idx++;
	}

	return (mx);
}
