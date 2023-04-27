#include "sort.h"

/**
* selection_sort - sort with Selection sort algorithm
* @array: array to sort
* @size: size of array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, k;
	int tmp;

	i = 0;
	while (i < size)
	{
		j = i;

		k = i;
		tmp = array[j];
		while (k < size)
		{
			if (tmp > array[k])
			{
				tmp = array[k];
				j = k;
			}
			k++;
		}
		if (j != i)
		{
			array[j] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
		i++;
	}
}
