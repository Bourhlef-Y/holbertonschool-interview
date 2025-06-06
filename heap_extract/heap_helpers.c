#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node
 * @value: value to put in the new node
 * Return: pointer to the new node, or NULL on failure
 */
heap_t *binary_tree_node(heap_t *parent, int value)
{
	heap_t *new_node;

	new_node = malloc(sizeof(heap_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * heapify_up - maintains the max heap property going up
 * @node: pointer to the current node
 */
void heapify_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
}

/**
 * _array_to_heap - builds a Max Binary Heap tree from an array
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 * Return: pointer to the root node of the created Binary Heap
 */
heap_t *_array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	size_t i;
	heap_t *new_node, *parent;
	size_t parent_index;

	if (!array || size == 0)
		return (NULL);

	/* Create root node */
	root = binary_tree_node(NULL, array[0]);
	if (!root)
		return (NULL);

	/* Insert remaining nodes */
	for (i = 1; i < size; i++)
	{
		new_node = binary_tree_node(NULL, array[i]);
		if (!new_node)
		{
			_binary_tree_delete(root);
			return (NULL);
		}

		/* Find parent node */
		parent_index = (i - 1) / 2;
		parent = root;
		size_t temp_index = parent_index;
		size_t level = 0;
		while (temp_index > 0)
		{
			temp_index /= 2;
			level++;
		}

		/* Navigate to parent position */
		while (level > 0)
		{
			if ((parent_index & (1 << (level - 1))) != 0)
				parent = parent->right;
			else
				parent = parent->left;
			level--;
		}

		/* Attach new node */
		if (i % 2 == 1)
			parent->left = new_node;
		else
			parent->right = new_node;
		new_node->parent = parent;

		/* Maintain heap property */
		heapify_up(new_node);
	}

	return (root);
}

/**
 * _binary_tree_delete - deletes an entire binary tree
 * @tree: pointer to the root node of the tree to delete
 */
void _binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	_binary_tree_delete(tree->left);
	_binary_tree_delete(tree->right);
	free(tree);
}
