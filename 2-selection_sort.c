#include "sort.h"

/**
* selection_sort - sort with Selection sort algorithm
* @array: array to sort
* @size: size of array
*/
void selection_sort(int *array, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		select_sort(i, array, size);
		i++;
	}
}

/**
* select_sort - sort with Selection sort algorithm
* @pos: position of data to sort
* @array: array to sort
* @size: size of array
*/
void select_sort(size_t pos, int *array, size_t size)
{
	size_t i;
	int tmp, temp;

	tmp = array[pos];
	for (i = 1; i <= (size - pos); i++)
	{
		if (tmp > array[pos + i])
		{
			temp = tmp;
			tmp = array[pos + i];
			array[pos + i] = temp;
		}
	}
	array[pos] = tmp;
	print_array(array, size);
}
