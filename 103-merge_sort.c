#include "sort.h"

void sub_merg(int *subarr, int *buff, size_t frnt, size_t center,
		size_t bck);
void merge_sort_recursive(int *subarr, int *buff, size_t frnt, size_t bck);
void merge_sort(int *array, size_t size);

/**
 * sub_merg - Sort a subarray of integers.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @frnt: The frnt index of the array.
 * @center: The middle index of the array.
 * @bck: The bck index of the array.
 */
void sub_merg(int *subarr, int *buff, size_t frnt, size_t center,
		size_t bck)
{
	size_t idx, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + frnt, center - frnt);

	printf("[right]: ");
	print_array(subarr + center, bck - center);

	for (idx = frnt, j = center; idx < center && j < bck; k++)
		buff[k] = (subarr[idx] < subarr[j]) ? subarr[idx++] : subarr[j++];
	for (; idx < center; idx++)
		buff[k++] = subarr[idx];
	for (; j < bck; j++)
		buff[k++] = subarr[j];
	for (idx = frnt, k = 0; idx < bck; idx++)
		subarr[idx] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + frnt, bck - frnt);
}

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
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
