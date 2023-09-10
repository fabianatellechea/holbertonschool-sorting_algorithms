#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 *
 * @list: Pointer to the pointer to the head of the linked list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *inner;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		inner = current;
		while (inner->prev != NULL && inner->n < inner->prev->n)
		{
			if (inner->next != NULL)
				inner->next->prev = inner->prev;
			inner->prev->next = inner->next;
			inner->next = inner->prev;
			inner->prev = inner->prev->prev;
			if (inner->prev != NULL)
				inner->prev->next = inner;
			else
				*list = inner;
			inner->next->prev = inner;
			print_list(*list);
		}
		current = current->next;
	}
}
