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
 * binary_tree_is_perfect - Vérifie si un arbre binaire est parfait
 * @tree: Pointeur vers la racine
 * Return: 1 si parfait, 0 sinon
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (!tree->left || !tree->right)
		return (0);
	return (binary_tree_is_perfect(tree->left) &&
		binary_tree_is_perfect(tree->right));
}

/**
 * find_parent - Trouve le parent pour le nouveau nœud
 * @root: Racine du tas
 * Return: Pointeur vers le parent
 */
heap_t *find_parent(heap_t *root)
{
	heap_t *parent = root;
	size_t height = 0;
	size_t i;
	size_t max_nodes;

	while (parent->left)
	{
		if (!parent->right || !binary_tree_is_perfect(parent->left))
			break;
		parent = parent->left;
		height++;
	}

	max_nodes = 1;
	for (i = 0; i < height; i++)
		max_nodes *= 2;

	if (!parent->left)
		return (parent);
	if (!parent->right)
		return (parent);

	parent = root;
	for (i = height - 1; i > 0; i--)
	{
		max_nodes /= 2;
		if (binary_tree_size(parent->left) < max_nodes)
			parent = parent->left;
		else
			parent = parent->right;
	}

	return (parent);
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

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	parent = find_parent(*root);
	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		swap_nodes(new_node, new_node->parent);
		new_node = new_node->parent;
	}

	return (new_node);
}
