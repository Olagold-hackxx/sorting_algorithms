#include "sort.h"

/**
* counting_sort - sort using counting sort algorithm
* @array: array to sort
* @size: size of array
*/
void counting_sort(int *array, size_t size)
{
	int *sorted_array, *count_array, max_num = 0, j;
	size_t i;

	if (!array || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > max_num)
			max_num = array[i];
	}
	count_array = (int *)malloc(sizeof(int) * (max_num + 1));
	if (count_array == NULL)
		return;
	for (j = 0; j < max_num + 1; j++)
		count_array[j] = 0;
	for (i = 0; i < size; i++)
		count_array[array[i]]++;
	for (j = 1; j <= max_num; j++)
		count_array[j] += count_array[j - 1];
	print_array(count_array, max_num + 1);
	sorted_array = (int *)malloc(sizeof(int) * size);
	if (sorted_array == NULL)
	{
		free(count_array);
		return;
	}
	for (j = size - 1; j >= 0; j--)
	{
		sorted_array[count_array[array[j]] - 1] = array[j];
		count_array[array[j]]--;
	}
	for (i = 0; i < size; i++)
	{
		array[i] = sorted_array[i];
	}
	free(count_array);
	free(sorted_array);
}
