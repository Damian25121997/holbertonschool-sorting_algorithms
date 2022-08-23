#include "sort.h"

/**
 * bubble_sort - function sort algorithm
 * @array: is an array
 * @size: is a size_t
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp = size;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
