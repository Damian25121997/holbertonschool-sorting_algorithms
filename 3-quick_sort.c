#include "sort.h"

void swap(int *i, int *j);
void quicksort_recursion(int *array, size_t size, int low, int high);
int partition(int *array, int low, int high);

/**
 * quick_sort - sort algorithms in Quicksort
 * @array: is an array
 * @size: is a size of array
 */

void quick_sort(int *array, size_t size)
{
	quicksort_recursion(array, size, 0, size - 1);
}

/**
 * swap - swaped two elements
 * @i: is a pointer
 * @j: is a pointer
 */

void swap(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

/**
 * quicksort_recursion - function recursive of QuickSoert
 * @array: is an array
 * @size: is a size of the array
 * @low: is a first element of an array
 * @high: is a last element of an array
 */

void quicksort_recursion(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high);
		print_array(array, size);
		quicksort_recursion(array, size, low, pivot - 1);
		quicksort_recursion(array, size, pivot + 1, high);
	}
}

/**
 * partition - is a function of pivot
 * @array: is an array
 * @low: is a first element of an array
 * @high: is a last element of an array
 * Return: sub-array
 */

int partition(int *array, int low, int high)
{
	int pivot_value = array[high];
	int i = low;
	int j = low;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot_value)
		{
			swap(&array[i], &array[j]);
			i++;
		}
	}
	swap(&array[i], &array[high]);
	return (i);
}
