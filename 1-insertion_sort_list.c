#include "sort.h"

/**
 * swap_nodes - Swap two nodes in listint_t list.
 * @h: Pointer to the head of the list.
 * @n1: Pointer to first node to swap.
 * @n2: Second node to swap.
 *
 * Description: This function swaps two nodes in doubly linked list.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	/* Update pointers to perform the swap */
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;

	/* Update the previous node's next pointer or the head if necessary */
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;

	/* Update the previous node of n1 */
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts list of integers using insertion sort.
 * @list: Pointer to the head of the list.
 *
 * Description: This function uses the insertion sort algorithm to sort
 *              a doubly linked list of integers.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	/* Check for edge cases and list emptiness */
	if (!list || !*list || !(*list)->next)
		return;

	/* Iterate through the list */
	for (iter = (*list)->next; iter; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;

		/* Perform the insertion sort */
		while (insert && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
