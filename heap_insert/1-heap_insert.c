#include "binary_trees.h"

/**
* binary_tree_height - measures the height of a binary tree
* @tree: pointer to the root node of the tree to measure the height
* Return: height of a binary tree or 0
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree || (!tree->left && !tree->right))
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	if (left >= right)
		return (left + 1);
	else
		return (right + 1);
}
/**
* binary_tree_nodes - counts nodes with at least 1 child__node in a binary tree
* @tree: pointer to the root node of the tree to count the number of nodes
* Return: number of nodes or 0
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes_right = 0;
	size_t nodes_left = 0;

	if (!tree)
		return (0);
	if (tree->left || tree->right)
	{
		nodes_right = binary_tree_nodes(tree->right);
		nodes_left = binary_tree_nodes(tree->left);
	}
	else
		return (0);
	return (nodes_right + nodes_left + 1);
}
/**
* binary_tree_is_perfect - checks if a binary tree is perfect
* @tree: pointer to the root node of the tree to check
* Return: 1 if perfect, else 0
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (!tree)
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	if (left == right)
	{
		if (!tree->left && !tree->right)
			return (1);
		if (tree->left && tree->right && binary_tree_is_perfect(tree->left)
		&& binary_tree_is_perfect(tree->right))
			return (1);
	}
	return (0);
}
/**
* swap - swaps nodes
* @parent: double pointer to the parent node
* @child: double pointer to the child__node nodes
*/
void swap(heap_t **parent, heap_t **child)
{
	heap_t *parent_node, *child_node, *node_left, *node_right,
	*node_child, *_parent;
	int left_right;

	parent_node = *parent;
	child_node = *child;
	if (child_node->n > parent_node->n)
	{
		if (child_node->left)
			child_node->left->parent = parent_node;
		if (child_node->right)
			child_node->right->parent = parent_node;
		if (parent_node->left == child_node)
			node_child = parent_node->right, left_right = 0;
		else
			node_child = parent_node->left, left_right = 1;
		node_left = child_node->left, node_right = child_node->right;
		if (left_right == 0)
		{child_node->right = node_child;
			if (node_child)
				node_child->parent = child_node;
			child_node->left = parent_node;
		}
		else
		{child_node->left = node_child;
			if (node_child)
				node_child->parent = child_node;
			child_node->right = parent_node;
		}
		if (parent_node->parent)
		{
			if (parent_node->parent->left == parent_node)
				parent_node->parent->left = child_node;
			else
				parent_node->parent->right = child_node;
		}
		_parent = parent_node->parent, child_node->parent = _parent;
		parent_node->parent = child_node, parent_node->left = node_left;
		parent_node->right = node_right, *parent = child_node;
	}
}

/**
* heap_insert - inserts a value in a max binary heap
* @root: double pointer to the root node of the Heap to insert the value
* @value: value to store in the node to be inserted
* Return: pointer to the created node or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (!(*root))
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	if (binary_tree_is_perfect(*root) ||
		!binary_tree_is_perfect((*root)->left))
	{
		if ((*root)->left)
		{
			new_node = heap_insert(&((*root)->left), value);
			swap(root, &((*root)->left));
			return (new_node);
		}
		else
		{
			new_node = (*root)->left = binary_tree_node(*root, value);
			swap(root, &((*root)->left));
			return (new_node);
		}
	}
	if ((*root)->right)
	{
		new_node = heap_insert(&((*root)->right), value);
		swap(root, (&(*root)->right));
		return (new_node);
	}
	else
	{
		new_node = (*root)->right = binary_tree_node(*root, value);
		swap(root, &((*root)->right));
		return (new_node);
	}
	return (NULL);
}
