#include <stdlib.h>
#include "binary_trees.h"

/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 */
static void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: height of tree, 0 if tree is NULL
 */
static size_t binary_tree_height(const heap_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	return (1 + (left > right ? left : right));
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: size of tree, 0 if tree is NULL
 */
static size_t binary_tree_size(const heap_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * heapify - maintains the max heap property
 * @root: pointer to the root node
 */
static void heapify(heap_t *root)
{
	heap_t *largest = root;
	heap_t *left = root->left;
	heap_t *right = root->right;

	if (left && left->n > largest->n)
		largest = left;

	if (right && right->n > largest->n)
		largest = right;

	if (largest != root)
	{
		swap(&root->n, &largest->n);
		heapify(largest);
	}
}

/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last, *current;
	size_t size, bit;

	if (!root || !*root)
		return (0);

	value = (*root)->n;
	size = binary_tree_size(*root);

	if (size == 1)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	/* Find the last node */
	current = *root;
	for (bit = 1 << (binary_tree_height(*root) - 1); bit > 1; bit >>= 1)
		current = size & bit ? current->right : current->left;

	last = size & 1 ? current->right : current->left;

	/* Replace root value with last node value */
	(*root)->n = last->n;

	/* Remove last node */
	if (size & 1)
		current->right = NULL;
	else
		current->left = NULL;

	free(last);
	heapify(*root);

	return (value);
}
