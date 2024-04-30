#include "sort.h"

/**
 * partition - A function that seperate an array to 2 unsorted parts:
 *              The first has all elements less than a pivot and the second
 *              has all elements greater than or equal to this pivot
 *
 * @array: A pointer to the array to be sorted
 * @size: The size of the array
 * @start: The beginnig index of the part to be sorted
 * @end: The end index of the part to be sorted
 *
 * Return: The index of the pivot
 */
size_t partition(int *array, size_t size, int start, int end)
{
	size_t index, curr_index = start;
	int temp, pivot = array[end];

	for (index = start; (int) index < end; index++)
	{
		if (array[index] < pivot)
		{
			if (curr_index != index)
			{
				temp = array[index];
				array[index] = array[curr_index];
				array[curr_index] = temp;
				print_array((const int *) array, size);
			}
			curr_index++;
		}
	}
	if (array[curr_index] != pivot)
	{
		array[end] = array[curr_index];
		array[curr_index] = pivot;
		print_array((const int *) array, size);
	}

	return (curr_index);
}

/**
 * lomuto_scheme - A funtion that sorts an array of integers
 *              in ascending order using the Quick sort algorithm
 *              and implement the Lomuto partition scheme
 *
 * @array: A pointer to the array to be sorted
 * @size: The size of the array
 * @start: The beginnig index of the part to be sorted
 * @end: The end index of the part to be sorted
 *
 * Return: Nothing
 */
void lomuto_scheme(int *array, size_t size, int start, int end)
{
	int pivot;

	if (end > start)
	{
		pivot = partition(array, size, start, end);
		lomuto_scheme(array, size, start, (pivot - 1));
		lomuto_scheme(array, size, (pivot + 1), end);
	}
}

/**
 * quick_sort - A function that sorts an array of integers
 *		in ascending order using the Quick sort algorithm
 *
 * @array: A pointer to the array to be sorted
 * @size: The size of the array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	lomuto_scheme(array, size, 0, (size - 1));
}
