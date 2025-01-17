#include "binary_trees.h"

/**
 * binary_tree_size - Mesure la taille d'un arbre binaire
 * @tree: Pointeur vers la racine
 * Return: Taille de l'arbre
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * swap_nodes - Échange les valeurs de deux nœuds
 * @node1: Premier nœud
 * @node2: Second nœud
 */
void swap_nodes(heap_t *node1, heap_t *node2)
{
	int temp = node1->n;

	node1->n = node2->n;
	node2->n = temp;
}

/**
 * get_last_node - Trouve le dernier nœud pour l'insertion
 * @root: Racine du tas
 * @size: Taille actuelle du tas
 * Return: Pointeur vers le parent du nouveau nœud
 */
heap_t *get_last_node(heap_t *root, size_t size)
{
	size_t bit;
	size_t mask = size;

	if (!root || size < 1)
		return (NULL);

	for (bit = 1; !(bit & size); bit <<= 1)
		continue;
	bit >>= 1;

	while (bit > 1)
	{
		bit >>= 1;
		if (mask & bit)
			root = root->right;
		else
			root = root->left;
	}

	return (root);
}

/**
 * heapify_up - Réorganise le tas de bas en haut
 * @node: Nœud à partir duquel commencer la réorganisation
 * Return: Pointeur vers le nœud final après réorganisation
 */
heap_t *heapify_up(heap_t *node)
{
	heap_t *current = node;

	while (current->parent && current->n > current->parent->n)
	{
		swap_nodes(current, current->parent);
		current = current->parent;
	}
	return (current);
}

/**
 * heap_insert - Insère une valeur dans un Max Binary Heap
 * @root: Double pointeur vers la racine du tas
 * @value: Valeur à insérer
 * Return: Pointeur vers le nœud créé, ou NULL en cas d'échec
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;
	size_t size;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size = binary_tree_size(*root);
	parent = get_last_node(*root, size);

	if (!parent)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (heapify_up(new_node));
}
