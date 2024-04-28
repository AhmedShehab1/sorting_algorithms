#include <stdio.h>
#include "sort.h"

/**
 *merge - make a merge
 *@arr: one from start to mid
 *@l: first element position
 *@m: array middle
 *@r: last element position
 *Return: void
 **/
void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	int n = r - l;
	int *arr1 = malloc(sizeof(int) * n1);
	int *arr2 = malloc(sizeof(int) * n2);
	size_t j = 0, i = 0, k;

	for (i = 0; i < n1; i++)
		arr1[i] = arr[i + l];

	for (j = 0; j < n2; j++)
		arr2[j] = arr[j + m + 1];

	i = 0, j = 0, k = l;

	while (i < n1 && j < n2)
	{
		if (arr1[i] <= arr2[j])
			arr[k++] = arr1[i++];
	else
		arr[k++] = arr2[j++];
	}

	while (i < n1)
		arr[k++] = arr1[i++];
	while (j < n2)
	arr[k++] = arr2[j++];

	printf("Merging...\n");
	printf("[left]: ");
	print_array(arr1, l);
	printf("[right]: ");
	print_array(arr2, r);
	printf("[Done]: ");
	print_array(&arr[k], l + r);
}


/**
 *Merge_Sorting - make a merge
 *@arr: one from start to mid
 *@l: first element position
 *@r: last element position
 *Return: void
 **/
void Merge_Sorting(int arr[], int l, int r)
{

	if (l < r)
	{
		int m = l + (r - l) / 2;

		Merge_Sorting(arr, l, m);
		Merge_Sorting(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

/**
 *merge_sort - function that sorts an array of integers
 *in ascending order using the Merge sort algorithm
 *@size: size of the list
 *@array: array of integers
 *Return: void
 */
void merge_sort(int *array, size_t size)
{
	Merge_Sorting(array, 0, size - 1);
}
