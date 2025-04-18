#include "binary_trees.h"
#include <stdlib.h>

/**
 * create_avl_node - Creates a new AVL node
 *
 * @parent: Pointer to the parent node
 * @value: Value to store in the node
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *create_avl_node(avl_t *parent, int value)
{
	avl_t *new_node = malloc(sizeof(avl_t));

	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * sorted_array_to_avl_helper - Recursively builds the AVL tree
 *
 * @array: Pointer to the first element of the array
 * @start: Starting index of the subarray
 * @end: Ending index of the subarray
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the root of the subtree
 */
avl_t *sorted_array_to_avl_helper(int *array, int start, int end,
								  avl_t *parent)
{
	avl_t *node;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	node = create_avl_node(parent, array[mid]);
	if (!node)
		return (NULL);

	node->left = sorted_array_to_avl_helper(array, start, mid - 1, node);
	node->right = sorted_array_to_avl_helper(array, mid + 1, end, node);

	return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 *
 * @array: Pointer to the first element of the array to be converted
 * @size: The number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (sorted_array_to_avl_helper(array, 0, size - 1, NULL));
}
