#include "sort.h"

/**
* knuth_seq - Get gaps with knuth sequence
* @size: size of array
* Return: array holding gaps
*/
size_t knuth_seq(size_t size)
{
	size_t i, j;
	size_t largst_gap;

	for (i = 1, j = 0; i < size; i = i * 3 + 1, j++)
	{
		largst_gap = i;
	}
	return (largst_gap);
}

/**
* shell_sort - Sorts an array of integers
* @array: The array to be sorted
* @size: Size of the array
* Return: Void
*/
void shell_sort(int *array, size_t size)
{
	size_t i, j, k, gap;
	int tmp;

	if (array == NULL || size == 0)
	{
		return;
	}

	gap = knuth_seq(size);
	for (i = gap; i > 0; i = (i - 1) / 3)
	{
		for (j = i; j < size; j++)
		{
			tmp = array[j];
			for (k = j; (k >= i) && (array[k - i] > tmp); k -= i)
				array[k] = array[k - i];
			array[k] = tmp;
		}
		print_array(array, size);
	}
}
