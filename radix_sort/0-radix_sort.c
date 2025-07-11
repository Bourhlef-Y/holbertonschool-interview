#include "sort.h"
#include <stdlib.h>

/**
 * get_max - Obtient la valeur maximale dans un tableau
 * @array: Le tableau d'entiers
 * @size: La taille du tableau
 * Return: La valeur maximale
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_radix - Effectue le tri par dénombrement pour Radix sort
 * @array: Le tableau à trier
 * @size: La taille du tableau
 * @exp: L'exposant actuel (position du chiffre)
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
	int *output;
	int count[10] = {0};
	size_t i;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	/* Compte l'occurrence de chaque chiffre */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/* Modifie count pour contenir les positions réelles */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Construit le tableau de sortie */
	for (i = size - 1; i < size; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/* Copie le tableau de sortie dans array[] */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);
	free(output);
}

/**
 * radix_sort - Trie un tableau d'entiers en ordre croissant
 * en utilisant l'algorithme Radix sort
 * @array: Le tableau à trier
 * @size: La taille du tableau
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	/* Effectue le tri par comptage pour chaque chiffre */
	for (exp = 1; max / exp > 0; exp *= 10)
		counting_sort_radix(array, size, exp);
}
