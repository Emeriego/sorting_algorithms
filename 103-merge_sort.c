#include "sort.h"
/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @frnt: The frnt index of the subarray.
 * @bck: The bck index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t frnt, size_t bck)
{
	size_t center;

	if (bck - frnt > 1)
	{
		center = frnt + (bck - frnt) / 2;
		merge_sort_recursive(subarr, buff, frnt, center);
		merge_sort_recursive(subarr, buff, center, bck);
		sub_merg(subarr, buff, frnt, center, bck);
	}
}


/**
 * sub_merg - Sorts a subarray.
 * @subarr: A subarray of an array.
 * @b: ber to store the sorted subarray.
 * @frnt: The left index of the array.
 * @center: Middle index of the array.
 * @bck: Bacck index of the array.
 */
void sub_merg(int *subarr, int *b, size_t frnt, size_t center,
		size_t bck)
{
	size_t idx, m;
	size_t k;

	k = 0;
	printf("Merging...\n[left]: ");
	print_array(subarr + frnt, center - frnt);

	printf("[right]: ");
	print_array(subarr + center, bck - center);

	for (idx = frnt, m = center; idx < center && m < bck; k++)
		b[k] = (subarr[idx] < subarr[m]) ? subarr[idx++] : subarr[m++];
	for (; idx < center; idx++)
		b[k++] = subarr[idx];
	for (; m < bck; m++)
		b[k++] = subarr[m];
	for (idx = frnt, k = 0; idx < bck; idx++)
		subarr[idx] = b[k++];

	printf("[Done]: ");
	print_array(subarr + frnt, bck - frnt);
}

/**
 * merge_sort - Sorts an array of integers in ascending
 * @array: An array of integers.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *b;

	if (array == NULL || size < 2)
		return;

	b = malloc(sizeof(int) * size);
	if (b == NULL)
		return;

	merge_sort_recursive(array, b, 0, size);

	free(b);
}
