#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: Pointer to the head of the skip list.
 * @value: The value to search for.
 *
 * Return: A pointer to the first node where the value is located,
 *         or NULL if the value is not present or the head is NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev = list;
	skiplist_t *node = NULL;

	if (list == NULL)
		return (NULL);

	/* Use the express lane to find the correct block */
	node = list->express;
	while (node)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
		if (node->n >= value)
			break;
		prev = node;
		node = node->express;
	}

	/* If we exited the loop, we are in the correct block */
	if (node == NULL)
	{
		node = prev;
		while (node->next)
			node = node->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
		prev->index, node->index);

	/* Perform linear search in the identified block */
	node = prev;
	while (node)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
		if (node->n == value)
			return (node);
		if (node->n > value)
			break;
		node = node->next;
	}
	return (NULL);
}
