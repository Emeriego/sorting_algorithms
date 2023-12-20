#include "sort.h"
/**
 * getMax - Get the maximum value in an array of integers.
 * @array: Array of integers.
 * @size: Size of array.
 *
 * Return: returns max int in an array.
 */
int getMax(int *array, size_t size)
{
	int mx;
	size_t idx;

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

/**
 * counting_sort - Sorts an array of integers in ascending order
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count;
	int *sorted;
	int mx;
	int idx;

	if (array == NULL || size < 2)
	{
		return;
	}
	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	mx = getMax(array, size);
	count = malloc(sizeof(int) * (mx + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}
	for (idx = 0; idx < (mx + 1); idx++)
		count[idx] = 0;
	for (idx = 0; idx < (int)size; idx++)
	{
		count[array[idx]] += 1;
	}
	for (idx = 0; idx < (mx + 1); idx++)
		count[idx] += count[idx - 1];
	print_array(count, mx + 1);
	for (idx = 0; idx < (int)size; idx++)
	{
		sorted[count[array[idx]] - 1] = array[idx];
		count[array[idx]] -= 1;
	}

	for (idx = 0; idx < (int)size; idx++)
		array[idx] = sorted[idx];
	free(sorted);
	free(count);
}
