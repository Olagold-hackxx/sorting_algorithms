#include "sort.h"
void swap_bitonic(int *arr, int a, int b);
void recBitonicSort(int *arr, int lo, int cnt, int dir, size_t n);
void compare(int *arr, int i, int j, int dir);
void bitonicMerge(int *arr, int lo, int cnt, int dir, size_t n);

void bitonic_sort(int *array, size_t size)
{
	recBitonicSort(array, 0, size, 1, size);
}

/**
 * swap_bitonic - swap value of array elements
 * @arr: array (for print)
 * @size: size of array (for print)
 * @a: pointer to array element
 * @b: pointer to array element
 */
void swap_bitonic(int *arr, int i, int j)
{
	int t;
	t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

void compare(int *arr, int i, int j, int dir)
{
	if (dir == (arr[i] > arr[j]))
	{
		swap_bitonic(arr, i, j);
	}
}


void bitonicMerge(int *arr, int lo, int cnt, int dir, size_t n)
{
	if (cnt>1)
	{
		int k=cnt/2;
		int i;
		for (i=lo; i<lo+k; i++)
		{
			compare(arr, i, i+k, dir);
		}
		if (cnt > 1)
		{
			if (dir == 1)
				printf("Result [%d/%lu] (UP)\n", cnt, n);
			else if (dir == 0)
				printf("Result [%d/%lu] (DOWN)\n", cnt, n);
			print_array(arr, cnt);
		}
		bitonicMerge(arr, lo, k, dir, n);
		if (cnt > 1)
		{
			if (dir == 1)
				printf("Result [%d/%lu] (UP)\n", cnt, n);
			else if (dir == 0)
				printf("Result [%d/%lu] (DOWN)\n", cnt, n);
			print_array(arr, cnt);
		}
		bitonicMerge(arr, lo+k, k, dir, n);
		
	}
}

void recBitonicSort(int *arr, int lo, int cnt, int dir, size_t n)
{
	if (dir == 1 && cnt > 1)
	{
		printf("Merging [%d/%lu] (UP)\n", cnt, n);
		print_array(arr, cnt);
	}
	else if (dir == 0 && cnt > 1)
	{
		printf("Merging [%d/%lu] (DOWN)\n", cnt, n);
		print_array(&arr[lo], cnt);
	}
	if (cnt>1)
	{
		int k = cnt/2;
		recBitonicSort(arr, lo, k, 1, n);
		recBitonicSort(arr, lo+k, k, 0, n);
		bitonicMerge(arr, lo, cnt, dir, n);
	}
}
