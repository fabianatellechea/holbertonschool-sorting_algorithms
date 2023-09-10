#include "sort.h"

/**
 * lomuto_partition - Implements Lomuto partitioning scheme
 * @array: Array to sort
 * @low: Lowest index of the subarray to be sorted
 * @high: Highest index of the subarray to be sorted
 * @size: size array
 *
 * Return: Index of the pivot after splitting
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * quicksort - Implements the Quick Sort sorting algorithm recursively
 * @array: Array to sort
 * @low: Lowest index of the subarray to be sorted
 * @high: Highest index of the subarray to be sorted
 * @size: size array
*/
void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = lomuto_partition(array, low, high, size);

		quicksort(array, low, pivot_index - 1, size);
		quicksort(array, pivot_index + 1, high, size);
	}
}
/**
 * quick_sort - Sort an array of integers in ascending order using Quick Sort
 * @array: Array to sort
 * @size: size array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
