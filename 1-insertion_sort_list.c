#include "sort.h"

/**
 * swap_nodes - A function that swap 2 nodes in a doubly linked list
 *
 * @head: A double pointer to the head node of the list
 * @first: A pointer to the first node to be swaped
 * @second: A pointer to the second node to be swaped
 *
 * Return: Nothing
 */
void swap_nodes(listint_t **head, listint_t *first, listint_t *second)
{
	if (!(*head) || !first || !second)
		return;

	if (first == (*head))
		(*head) = second;
	else
		first->prev->next = second;
	second->prev = first->prev;
	first->prev = second;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
}

/**
 * insertion_sort_list - A function that sorts a doubly linked list of integers
 *			in ascending order using the Insertion sort algorithm
 *
 * @list: A double pointer to a doubly linked list node
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *insert_node, *sorted_node, *temp;

	if (!list || !(*list) || (*list)->next == NULL)
		return;

	insert_node = (*list)->next;
	while (insert_node != NULL)
	{
		temp = insert_node->next;
		sorted_node = insert_node->prev;
		while (sorted_node != NULL && insert_node->n < sorted_node->n)
		{
			swap_nodes(list, sorted_node, insert_node);
			sorted_node = insert_node->prev;
			print_list((const listint_t *)*list);
		}
		insert_node = temp;
	}
}
