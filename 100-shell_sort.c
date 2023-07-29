#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 *
 * Description: This function swaps two integers in an array.
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sorts array of integers in ascending order using Shell Sort.
 * @array: Array of integers.
 * @size: The size of the array.
 *
 * Description: This function uses the Shell Sort algorithm
 *             with the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (!array || size < 2)
		return;

	/* Calculate initial gap using the Knuth interval sequence */
	for (gap = 1; gap < size; gap = gap * 3 + 1)
		;

	/* Decrease gap before first iteration */
	gap /= 3;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			/* Perform insertion sort within the current gap */
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_ints(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
