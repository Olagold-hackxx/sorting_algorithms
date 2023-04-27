#include "sort.h"

/**
* quick_sort - sort with quick sort algorithm
* @array: array to sort
* @size: size of array
*/

void quick_sort(int *array, size_t size)
{
	int firstIndex, lastIndex;

	firstIndex = 0;
	lastIndex = size - 1;

	if (size < 2)
		return;

	quickSort(array, firstIndex, lastIndex, size);
}

/**
* quickSort - sort using Quicksort Algorithm
* @array: array to sort
* @firstIndex: first index of array
* @lastIndex: last index of array
* @size: size of array
*/
void quickSort(int *array, int firstIndex, int lastIndex, size_t size)
{
	int part;

	if (firstIndex < lastIndex)
	{
		part = partition(array, firstIndex, lastIndex, size);

		quickSort(array, firstIndex, part - 1, size);
		quickSort(array, part + 1, lastIndex, size);
	}
}

/**
* partition - partition array
* @array: array to partition
* @firstIndex: first index of each partition
* @lastIndex: last index of each partition
* @size: size of array
* Return: lastindex of a partition the array
*/
int partition(int *array, int firstIndex, int lastIndex, size_t size)
{
	int i, j, pivot;

	pivot = array[lastIndex];
	i = firstIndex;

	for (j = firstIndex; j < lastIndex; j++)
	{
		if (array[j] < pivot)
		{
			swap_arr(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
			i++;
		}
	}
	swap_arr(&array[i], &array[lastIndex]);
	if (i != j)
		print_array(array, size);
	return (i);
}

/**
* swap_arr - swap array data
* @a: ptr to data a
* @b: ptr to data b
*/
void swap_arr(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
