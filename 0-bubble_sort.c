#include "sort.h"
/**
*bubble_sort - sorts an array of integers in ascending order
*@array: array to order
*@size: size of array
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j, tmp;

	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[i])
			{
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
				print_array(array, size);
			}
		}
	}
}
