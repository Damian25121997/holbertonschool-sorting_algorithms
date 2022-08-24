#include "sort.h"

void swap(int *i, int *j);
void quicksort_recursion(int *array, size_t size, int low, int high);
int partition(int * array, int low, int high);

/**
 * quick_sort - sort algorithms in Quicksort
 * @array: is an array
 * @size: is a size of array
 */

void quick_sort(int *array, size_t size)
{
	quicksort_recursion(array, 0, size, size - 1);
}

void swap(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

void quicksort_recursion( int *array, size_t size, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high);
		print_array(array[], size);
		quicksort_recursion(array, size, low, pivot - 1);
		quicksort_recursion(array, size, pivot + 1, high);
	}
	
}

int partition(int *array, int low, int high)
{
	int pivot_value = array[high];

	int i = low;

	for (int j = low; j < high; j++)
	{
		if (array[j] <= pivot_value)
		{
			swap(&array[i], &array[j]);
			i++;
		}
	}
	swap(&array[i], &array[high]);
	return i;
}
