#include "sort.h"
/**
 * exchng - swap two int
 * @a: int
 * @b: int
 */
void exchng(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

