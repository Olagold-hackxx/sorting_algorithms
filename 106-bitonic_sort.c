#include "sort.h"
void swap_bitonic(int *arr, int a, int b);
void recBitonicSort(int *arr, int lo, int cnt, int dir, size_t n);
void bitonicMerge(int *arr, int lo, int cnt, int dir);


/**
 * bitonic_sort - sort using bitonic sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void bitonic_sort(int *array, size_t size)
{
	recBitonicSort(array, 0, size, 1, size);
}

/**
 * swap_bitonic - swap value of array elements
 * @arr: array
 * @i: index to node in array to swap data
 * @j: index to node in array to swap data
 */
void swap_bitonic(int *arr, int i, int j)
{
	int t;

	t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

/**
 * bitonicMerge - swap and merge splitted part of array
 * @arr: array
 * @lo: first index
 * @cnt: last index
 * @dir: 1 for ascending swapping 0 for descending
 */
void bitonicMerge(int *arr, int lo, int cnt, int dir)
{
	int i, k;

	if (cnt > 1)
	{
		k = cnt / 2;
		for (i = lo; i < lo + k; i++)
		{
			if (dir == (arr[i] > arr[i + k]))
			{
				swap_bitonic(arr, i, i + k);
			}
		}
		bitonicMerge(arr, lo, k, dir);
		bitonicMerge(arr, lo + k, k, dir);
	}
}

/**
 * recBitonicSort - split and sort recursively
 * @arr: array
 * @lo: first index
 * @cnt: last index
 * @dir: 1 for ascending swapping 0 for descending
 * @n: size of array
 */
void recBitonicSort(int *arr, int lo, int cnt, int dir, size_t n)
{
	int k;

	if (cnt > 1)
	{
		if (dir == 1)
		{
			printf("Merging [%d/%lu] (UP)\n", cnt, n);
			print_array(&arr[lo], cnt);
		}
		else if (dir == 0)
		{
			printf("Merging [%d/%lu] (DOWN)\n", cnt, n);
			print_array(&arr[lo], cnt);
		}
		k = cnt / 2;
		recBitonicSort(arr, lo, k, 1, n);
		recBitonicSort(arr, lo + k, k, 0, n);
		bitonicMerge(arr, lo, cnt, dir);
		if (dir == 1)
			printf("Result [%d/%lu] (UP)\n", cnt, n);
		else if (dir == 0)
			printf("Result [%d/%lu] (DOWN)\n", cnt, n);
		print_array(&arr[lo], cnt);
	}
}
