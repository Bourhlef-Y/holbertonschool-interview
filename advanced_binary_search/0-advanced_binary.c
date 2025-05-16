#include "search_algos.h"

/**
 * print_array - Imprime un tableau
 * @array: Tableau à imprimer
 * @left: Index de début
 * @right: Index de fin
 */
void print_array(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * binary_recursive - Recherche binaire récursive
 * @array: Tableau trié
 * @left: Index de début
 * @right: Index de fin
 * @value: Valeur à chercher
 * Return: Index de la première occurrence ou -1
 */
int binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (right < left)
		return (-1);

	print_array(array, left, right);

	mid = left + (right - left) / 2;

	if ((mid == left || array[mid - 1] < value) && array[mid] == value)
		return (mid);

	if (array[mid] >= value)
		return (binary_recursive(array, left, mid, value));

	return (binary_recursive(array, mid + 1, right, value));
}

/**
 * advanced_binary - Recherche la première occurrence d'une valeur
 * @array: Tableau trié
 * @size: Taille du tableau
 * @value: Valeur à chercher
 * Return: Index de la première occurrence ou -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);

	return (binary_recursive(array, 0, size - 1, value));
}
