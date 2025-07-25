#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: list to be checked
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
	listint_t *current = list;
	listint_t *new_node = list;

	while (current && new_node && new_node->next)
	{
		current = current->next;
		new_node = new_node->next->next;

		if (current == new_node)
			return (1);
	}
	return (0);
}