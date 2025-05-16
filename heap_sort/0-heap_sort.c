#include "sort.h"

/**
 * swap - Échange deux éléments dans un tableau
 * @a: Premier élément
 * @b: Deuxième élément
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - Implémente l'algorithme sift-down
 * @array: Tableau à trier
 * @size: Taille du tas
 * @root: Racine du sous-tas
 * @total_size: Taille totale du tableau pour l'impression
 */
void sift_down(int *array, size_t size, size_t root, size_t total_size)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		swap(&array[root], &array[largest]);
		print_array(array, total_size);
		sift_down(array, size, largest, total_size);
	}
}

/**
 * heap_sort - Trie un tableau d'entiers par tri par tas
 * @array: Tableau à trier
 * @size: Taille du tableau
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	/* Construction du tas max */
	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, i, size);

	/* Extraction des éléments un par un */
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, i, 0, size);
	}
}
