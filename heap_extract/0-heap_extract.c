#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * heap_size - Calculates the size of a binary heap
 * @tree: Pointer to the root node of the heap
 * Return: Size of the heap
 */
size_t heap_size(const heap_t *tree)
{
	if (!tree)
		return (0);
	return (1 + heap_size(tree->left) + heap_size(tree->right));
}

/**
 * get_last_node - Gets the last node in level-order traversal
 * @root: Pointer to the root node
 * @index: Current index in level-order
 * @size: Total size of the heap
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root, size_t index, size_t size)
{
	if (!root || index > size)
		return (NULL);

	if (index == size)
		return (root);

	heap_t *left_result = NULL, *right_result = NULL;

	if (root->left)
		left_result = get_last_node(root->left, index * 2, size);
	if (root->right)
		right_result = get_last_node(root->right, index * 2 + 1, size);

	return (left_result ? left_result : right_result);
}

/**
 * heapify_down - Restores heap property by moving node down
 * @node: Pointer to the node to heapify down from
 */
void heapify_down(heap_t *node)
{
	heap_t *largest = node;
	heap_t *left = node->left;
	heap_t *right = node->right;
	int temp;

	if (left && left->n > largest->n)
		largest = left;

	if (right && right->n > largest->n)
		largest = right;

	if (largest != node)
	{
		temp = node->n;
		node->n = largest->n;
		largest->n = temp;

		heapify_down(largest);
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * Return: Value stored in the root node on success, 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *last_node;
	size_t size;
	int root_value;

	if (!root || !*root)
		return (0);

	root_value = (*root)->n;

	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (root_value);
	}

	size = heap_size(*root);
	last_node = get_last_node(*root, 1, size);

	(*root)->n = last_node->n;

	if (last_node->parent)
	{
		if (last_node->parent->left == last_node)
			last_node->parent->left = NULL;
		else
			last_node->parent->right = NULL;
	}
	free(last_node);

	heapify_down(*root);

	return (root_value);
}
