#include "sort.h"

void radix_count(int *array, size_t size, int place);
int get_max(int *array, size_t size);

/**
 * radix_sort - Sort an array implementing RadixSort
 * @array: An array of integers.
 * @size: The size of the array.
 */

void radix_sort(int *array, size_t size)
{
	int exp, m;

	if (array == NULL || size < 2)
		return;

	m = get_max(array, size);
	for (exp = 1; m / exp > 0; exp *= 10)
	{
		radix_count(array, size, exp);
		print_array(array, size);
	}
}

/**
 * radix_count - Sort the significant digit
 * @array: An array of integers.
 * @size: The size of the array.
 * @place: The significant digit to sort on.
 */

void radix_count(int *array, size_t size, int place)
{
	size_t i;
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};

	for (i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
}

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: The maximum integer in the array.
 */

int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
