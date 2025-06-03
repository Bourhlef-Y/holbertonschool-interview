#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _putchar(char c);

/**
 * is_digit - vérifie si une chaîne ne contient que des chiffres
 * @str: chaîne à vérifier
 * Return: 1 si que des chiffres, 0 sinon
 */
int is_digit(char *str)
{
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }
    return 1;
}

/**
 * multiply - multiplie deux nombres stockés dans des chaînes
 * @s1: premier nombre
 * @s2: deuxième nombre
 */
void multiply(char *s1, char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int *result = calloc(len1 + len2, sizeof(int));
    int i, j, carry;

    if (!result)
        exit(98);

    // Multiplication
    for (i = len1 - 1; i >= 0; i--)
    {
        for (j = len2 - 1; j >= 0; j--)
        {
            result[i + j + 1] += (s1[i] - '0') * (s2[j] - '0');
        }
    }

    // Gestion des retenues
    for (i = len1 + len2 - 1; i > 0; i--)
    {
        carry = result[i] / 10;
        result[i - 1] += carry;
        result[i] %= 10;
    }

    // Affichage du résultat
    i = 0;
    while (i < len1 + len2 - 1 && result[i] == 0)
        i++;
    
    while (i < len1 + len2)
    {
        _putchar(result[i] + '0');
        i++;
    }
    _putchar('\n');

    free(result);
}

/**
 * main - point d'entrée du programme
 * @argc: nombre d'arguments
 * @argv: tableau d'arguments
 * Return: 0 en cas de succès, 98 en cas d'erreur
 */
int main(int argc, char *argv[])
{
    if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
    {
        printf("Error\n");
        return 98;
    }

    if (argv[1][0] == '0' || argv[2][0] == '0')
    {
        _putchar('0');
        _putchar('\n');
        return 0;
    }

    multiply(argv[1], argv[2]);
    return 0;
} 