#include "sort.h"
void TopDownSplitMerge(int *, int *, int, int);
void TopDownMerge(int *, int *, int, int, int);
void copy_array(int *, int *, int, int);

/**
* merge_sort - sort using merge sort algorithm
* @array: array to sort
* @size: size of array
*/
void merge_sort(int *array, size_t size)
{
	int *sortArray;

	sortArray = (int *)malloc(sizeof(int) * size);
	if (sortArray ==  NULL)
		return;
	copy_array(array, sortArray, 0, size + 0);
	TopDownSplitMerge(array, sortArray, 0, size + 0);

	free(sortArray);
}

/**
* TopDownSplitMerge - split array into 2 and merge each partition recursively
* @array: array to sort
* @sortArray: copy sorted array
* @firstIndex: first index of each array partiton
* @size: size of array partiton
*/
void TopDownSplitMerge(int *array, int *sortArray, int firstIndex, int size)
{
	int middleIndex;

	if ((size - firstIndex) <= 1)
		return;
	middleIndex = (size + firstIndex) / 2;
	TopDownSplitMerge(array, sortArray, firstIndex, middleIndex);
	TopDownSplitMerge(array, sortArray, middleIndex, size);

	TopDownMerge(sortArray, array, firstIndex, middleIndex, size);
}

/**
* TopDownMerge - Merge partition left to right
* @arr: array to sort
* @s_arr: copy sorted array
* @firstIndex: first index of each array partition
* @midIndex: middle index of each array partition
* @size: size of array partiton
*/
void TopDownMerge(int *arr, int *s_arr, int firstIndex, int midIndex, int size)
{
	int i, j, k;

	i = firstIndex;
	j = midIndex;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(&arr[firstIndex], midIndex - firstIndex);
	printf("[right]: ");
	print_array(&arr[midIndex], size - midIndex);
	for (k = firstIndex; k < size; k++)
	{
		if ((arr[i] <= arr[j] || j >= size) && (i < midIndex))
		{
			s_arr[k] = arr[i];
			i++;
		}
		else
		{
			s_arr[k] = arr[j];
			j++;
		}
	}
	printf("[Done]: ");
	copy_array(s_arr, arr, firstIndex, size);
	print_array(&s_arr[firstIndex], size - firstIndex);
}

/**
* copy_array - copy array values to another array
* @array: array to copy its values
* @copied_array: array to paste values to
* @i: index to start with
* @size: size of array
*/
void copy_array(int *array, int *copied_array, int i, int size)
{
	for (; i < size; i++)
		copied_array[i] = array[i];
}
