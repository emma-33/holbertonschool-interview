#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list
 *
 * @head: A pointer to the head of the list to search
 *
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head;
	listint_t *fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			return (helper_loop(head, slow));
		}
	}
	return (NULL);
}

/**
 * helper_loop - Check if a node is in a list
 *
 * @head: A pointer to the head of the loop
 * @slow: Current node to check
 *
 * Return: The address of the node
 */
listint_t *helper_loop(listint_t *head, listint_t *slow)
{
	listint_t *entry = head;

	while (entry != slow)
	{
		entry = entry->next;
		slow = slow->next;
	}
	return (entry);
}