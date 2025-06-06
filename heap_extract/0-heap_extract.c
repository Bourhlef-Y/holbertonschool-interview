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
 * get_last_node - gets the last level-order node
 * @root: pointer to the root node
 * Return: pointer to the last node
 */
static heap_t *get_last_node(heap_t *root)
{
	heap_t **queue;
	heap_t *last = NULL;
	size_t i = 0;
	size_t size = 0;

	if (!root)
		return (NULL);

	/* Count nodes to determine queue size */
	queue = malloc(sizeof(heap_t *) * 1024);
	if (!queue)
		return (NULL);

	queue[i] = root;
	size++;

	while (i < size)
	{
		if (queue[i]->left)
		{
			queue[size] = queue[i]->left;
			size++;
		}
		if (queue[i]->right)
		{
			queue[size] = queue[i]->right;
			size++;
		}
		i++;
	}

	last = queue[size - 1];
	free(queue);
	return (last);
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
	heap_t *last;

	if (!root || !*root)
		return (0);

	value = (*root)->n;

	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	last = get_last_node(*root);
	if (!last)
		return (0);

	/* Replace root value with last node value */
	(*root)->n = last->n;

	/* Remove last node from its parent */
	if (last->parent->right == last)
		last->parent->right = NULL;
	else
		last->parent->left = NULL;

	free(last);
	heapify(*root);

	return (value);
}
