#include "sort.h"
/**
 * bubble_sort - Sorts Given Array Using Bubble Sort Algorithm
 * @array: Array To Be Sorted
 * @size: Size Of The Array
 *
*/
void bubble_sort(int *array, size_t size)
{
	int i, j, temp, flag = 0;

	if (size < 2)
		exit(EXIT_SUCCESS);

	for (i = 0; i < (int)(size - 1); i++)
	{
		for (j = 0; j < (int)(size - 1) - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				flag = 1;
				print_array((const int *) array, size);
			}
		}
		if (flag != 1)
			break;
		flag = 0;
	}
}
