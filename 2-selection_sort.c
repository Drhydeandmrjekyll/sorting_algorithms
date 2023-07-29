#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 *
 * Description: Function swaps two integers in array.
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sorts array of integers in ascending order using Bubble Sort.
 * @array: Array of integers.
 * @size: The size of array.
 *
 * Description: Function sorts the array using Bubble Sort algorithm and
 *              prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
	/* Assume the current element is the smallest (i.e., the "bubble") */
	int *bubble = array + i;

	/* Find the smallest element in the remaining unsorted part of the array */
	for (j = i + 1; j < size; j++)
	{
		if (array[j] < *bubble)
			bubble = array + j;
	}

	/* If the current element is not the smallest, swap them */
	if (array + i != bubble)
		{
		swap_ints(array + i, bubble);
		print_array(array, size);
		}
	}
}
