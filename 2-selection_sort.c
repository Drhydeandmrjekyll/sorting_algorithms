#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 *
 * @a: Pointer to the first integer to swap.
 * @b: Pointer to the second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sorts array of integers using Selection Sort algorithm.
 *
 * @array: Array to be sorted.
 * @size: Number of elements in @array.
 *
 * Description: Uses selection sort algorithm to sort the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;

		/* Find minimum element in the remaining unsorted array */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *min)
				min = array + j;
		}

		/* If minimum element is not already at its correct position, swap */
		if (array + i != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
