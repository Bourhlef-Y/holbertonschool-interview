#include "palindrome.h"

/**
 * is_palindrome - Vérifie si un nombre est un palindrome
 * @n: Le nombre à vérifier
 *
 * Return: 1 si c'est un palindrome, 0 sinon
 */
int is_palindrome(unsigned long n)
{
	unsigned long reversed = 0;
	unsigned long original = n;

	/* Construit le nombre inversé */
	while (n > 0)
	{
		reversed = (reversed * 10) + (n % 10);
		n /= 10;
	}

	/* Compare le nombre original avec son inverse */
	return (original == reversed);
}
