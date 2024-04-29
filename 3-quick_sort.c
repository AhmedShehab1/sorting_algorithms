#include "sort.h"

/**
 * quick_sort - Sorts Array Using Quick Sort
 * Algorithm (Lomuto partition scheme)
 * @array: Array To Be Sorted
 * @size: Size Of The Array
 *
*/
void quick_sort(int *array, size_t size)
{
	int  pivotNewIndex;
	static int low, high, i;

	if (size < 2)
		return;
	if (i == 0)
		high = size - (++i);
	if (low < high)
	{
		pivotNewIndex = partition(array, low, high, size);
		if (pivotNewIndex - 1 < low)
		{
			low = pivotNewIndex + 1;
		}
		else if (high < pivotNewIndex  + 1)
		{
			high = pivotNewIndex - 1;
		}
		quick_sort(array, size);
	}
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
	int pivot, index, i, temp;

	pivot = array[high];
	index = low - 1;

	for (i = 0; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			index++;

			temp = array[i];
			array[i] = array[index];
			array[index] = temp;
			if (array[index] != array[i])
			{
				print_array(array, size);
			}
		}
	}

	temp = array[index + 1];
	array[index + 1] = array[high];
	array[high] = temp;
	if (array[index + 1] != array[high])
		print_array(array, size);

	return (index + 1);
}
