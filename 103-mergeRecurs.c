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
