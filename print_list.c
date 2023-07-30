#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers using Bubble Sort algorithm.
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, j;
	int swapped;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; ++i)
	{
		swapped = 0; /* Indicates if any swap occurred during this pass */
		for (j = 0; j < size - i - 1; ++j)
		{
			/* Compare adjacent elements and swap if necessary */
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
			}
		}

		/* If no two elements were swapped during the inner loop, the array is already sorted */
		if (swapped == 0)
			break;
	}
}

/* The rest of the code remains the same */

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}
