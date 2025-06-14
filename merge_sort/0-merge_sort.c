#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * merge - Fusionne deux sous-tableaux triés en un seul tableau trié
 * @array: Tableau original
 * @left: Index de début
 * @mid: Index du milieu
 * @right: Index de fin
 * @work_array: Tableau de travail temporaire
 */
void merge(int *array, size_t left, size_t mid, size_t right, int *work_array)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			work_array[k++] = array[i++];
		else
			work_array[k++] = array[j++];
	}

	while (i < mid)
		work_array[k++] = array[i++];
	while (j < right)
		work_array[k++] = array[j++];

	for (i = left; i < right; i++)
		array[i] = work_array[i];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_sort_recursive - Implémentation récursive du tri fusion
 * @array: Tableau à trier
 * @left: Index de début
 * @right: Index de fin
 * @work_array: Tableau de travail temporaire
 */
void merge_sort_recursive(int *array, size_t left,
size_t right, int *work_array)
{
	size_t mid;

	if (right - left <= 1)
		return;

	mid = left + (right - left) / 2;

	merge_sort_recursive(array, left, mid, work_array);
	merge_sort_recursive(array, mid, right, work_array);
	merge(array, left, mid, right, work_array);
}

/**
 * merge_sort - Trie un tableau d'entiers dans l'ordre croissant
 * @array: Le tableau à trier
 * @size: Taille du tableau
 */
void merge_sort(int *array, size_t size)
{
	int *work_array;

	if (!array || size < 2)
		return;

	work_array = malloc(sizeof(int) * size);
	if (!work_array)
		return;

	merge_sort_recursive(array, 0, size, work_array);

	free(work_array);
}
