#include "sort.h"

/**
 * swap_ints - Swap two integers in array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 *
 * Description: This function swaps two integers in array.
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sort array of integers in ascending order using Bubble Sort.
 * @array: Array of integers.
 * @size: The size of the array.
 *
 * Description: This function sorts array using Bubble Sort algorithm and
 *              prints array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	int swapped;

	if (array == NULL || size < 2)
		return;
	
	do
	{
		swapped = 0;
		for (i = 1; i < len; i++)
		{
			if (array[i - 1] > array[i])
			{
				swap_ints(array + i - 1, array + i);
				swapped = 1;
				print_array(array, size);
			}
		}
		len--;
	} while (swapped);
}
