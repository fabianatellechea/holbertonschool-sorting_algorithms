#include "sort.h"
/**
 *selection_sort - function that sorts an array of int in asc order
 *@array: array to sort
 *@size: size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, tmp, min;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}

		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
