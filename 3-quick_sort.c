#include "sort.h"

void quick_sort_2(int *array, size_t size, int low, int high)
{
	int pivotNewIndex;

	if (high > low)
	{
		pivotNewIndex = partition(array, low, high, size);
		quick_sort_2(array, size, low, pivotNewIndex - 1);
		quick_sort_2(array, size, pivotNewIndex + 1, high);
	}
}

/**
 * quick_sort - Sorts Array Using Quick Sort
 * Algorithm (Lomuto partition scheme)
 * @array: Array To Be Sorted
 * @size: Size Of The Array
 *
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_2(array, size, 0, size - 1);
}

/**
 * partition - Lomuto Partition Scheme
 * @array: Array To Be Sorted
 * @low: Lower Bound Of The Array
 * @high: Upper Bound Of The Array
 * @size: Size Of The Array
 *
 * Return: New Position Of Pivot Element
*/
int partition(int *array, int low, int high, int size)
{
	size_t i, index = low;
	int pivot = array[high], temp;

	for (i = low; (int) i < high; i++)
	{
		if (array[i] < pivot)
		{
			if (index != i)
			{
				temp = array[i];
				array[i] = array[index];
				array[index] = temp;
				print_array(array, size);
			}
			index++;
		}
	}
	if (array[index] != array[high])
	{
		array[index] = array[high];
		array[high] = pivot;
		print_array(array, size);
	}

	return (index);
}
