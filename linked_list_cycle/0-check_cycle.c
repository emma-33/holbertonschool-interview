#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: list to be checked
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
	listint_t *current;
	listint_t *temp;

	current = list;
	temp = list;

	while (current && temp && temp->next)
	{
		current = current->next;
		temp = temp->next->next;

		if (current == temp)
			return (1);
	}
	return (0);
}