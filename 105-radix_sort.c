#include "sort.h"
/**
 * lsd - count sort with LSD
 * @array: array to sort
 * @size: size of the array
 * @lsd: least significant digit
 */
void lsd(int *array, size_t size, size_t lsd)
{
	int c_arr[10];
	int *out;
	int ls, ms;
	size_t kns, num;

	c_arr = {0};
	num = 0;
	out = malloc(sizeof(int) * size);
	for (kns = 0; kns < size; kns++)
		c_arr[(array[kns] / lsd) % 10]++;
	for (ls = 1; ls < 10; ls++)
		c_arr[ls] += c_arr[ls - 1];

	for (ms = size - 1; ms >= 0; ms--)
	{
		out[c_arr[(array[ms] / lsd) % 10] - 1] = array[ms];
		c_arr[(array[ms] / lsd) % 10]--;
	}

	while (num < size)
	{
		array[num] = out[num];
		num++;
	}
	free(out);
}

/**
 * radix_sort - sorts an array following the Radix sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max;
	size_t i, lsd;

	if (!array || size < 2)
		return;

	max = 0;
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];

	for (lsd = 1; max / lsd > 0; lsd *= 10)
	{
		lsd(array, size, lsd);
		print_array(array, size);
	}
}
