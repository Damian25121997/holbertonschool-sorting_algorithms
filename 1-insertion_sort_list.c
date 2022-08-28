#include "sort.h"

void swap(listint_t **list, listint_t **second, listint_t *first);
/**
 * insertion_sort_list - insertion sort algorithm
 * @list: is a list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *first = NULL;
	listint_t *second = NULL;
	listint_t *temp = NULL;

	if (!list || !*list || !(*list)->next)
		return;
	for (first = (*list)-> next; first != NULL; first = temp)
	{
		temp = first->next;
		second = first->prev;
		while (second != NULL && first->n < second->n)
		{
			swap(list, &second, first);
			print_list(*list);
		}
	}
}

/**
 * swap - swap two nodes
 * @first: is a node
 * @second: is a node
 */

void swap(listint_t **list, listint_t **second, listint_t *first)
{
	(*second)->next = first->next;
	if (first->next != NULL)
		first->next->prev = *second;
	first->prev = (*second)->prev;
	first->next = *second;
	if((*second)->prev != NULL)
		(*second)->prev->next = first;
	else
		*list = first;
	(*second)->prev = first;
	*second = first->prev;
}
