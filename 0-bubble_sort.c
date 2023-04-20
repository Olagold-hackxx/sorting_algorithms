#include "sort.h"

/**
* bubble_sort - sort with bubble sort algorithm
* array - array to sort
* size - size of array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, n;
	int temp;

	for (n = 0; n < size; n++)
	{
		for (i = 0; i < size; i++)
		{
			if (i < size - 1)
			{
				if (array[i] > array[i + 1])
				{
					temp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = temp;
					print_array(array, size);
				}
			}
		}
	}
}