#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/*_Task0_*/
void bubble_sort(int *array, size_t size);

/*_Task1_*/
void swap_nodes(listint_t **head, listint_t *first, listint_t *second);
void insertion_sort_list(listint_t **list);

/*_Task2_*/
void selection_sort(int *array, size_t size);

/*_Task3_*/
void quick_sort(int *array, size_t size);
int partition(int *array, int low, int high, int size);

/*_Task7_*/
void Merge_Sorting(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void merge_sort(int *array, size_t size);

#endif /*_sort.h_*/
