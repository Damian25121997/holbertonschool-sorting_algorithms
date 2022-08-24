#include "sort.h"

void swap(listint_t *first, listint_t *second);
/**
 * insertion_sort_list - insertion sort algorithm
 * @list: is a list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *front = *list;
	listint_t *back = NULL;

	if (front == NULL)
		return;
	while (front != NULL)
	{
		back = front->next;
		while (back != NULL && back->prev != NULL && back->n < back->prev->n)
		{
			swap(back, back->prev);
			print_list(*list);
			back = back->prev;
		}
		front = front->next;
	}
}

/**
 * swap - swap two nodes
 * @first: is a node
 * @second: is a node
 */

void swap(listint_t *first, listint_t *second)
{
	int value;

	value = first->n;
	(*(int *)&(first->n)) = second->n;
	(*(int *)&(second->n)) = value;
}
