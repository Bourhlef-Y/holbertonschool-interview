#include "slide_line.h"

/**
 * merge_left - Fusionne les nombres identiques vers la gauche
 * @line: Tableau d'entiers
 * @size: Taille du tableau
 */
static void merge_left(int *line, size_t size)
{
    size_t i;
    
    for (i = 0; i < size - 1; i++)
    {
        if (line[i] != 0 && line[i] == line[i + 1])
        {
            line[i] *= 2;
            line[i + 1] = 0;
        }
    }
}

/**
 * merge_right - Fusionne les nombres identiques vers la droite
 * @line: Tableau d'entiers
 * @size: Taille du tableau
 */
static void merge_right(int *line, size_t size)
{
    size_t i;
    
    for (i = size - 1; i > 0; i--)
    {
        if (line[i] != 0 && line[i] == line[i - 1])
        {
            line[i] *= 2;
            line[i - 1] = 0;
        }
    }
}

/**
 * slide_left - Déplace tous les nombres vers la gauche
 * @line: Tableau d'entiers
 * @size: Taille du tableau
 */
static void slide_left(int *line, size_t size)
{
    size_t i, pos = 0;
    
    for (i = 0; i < size; i++)
    {
        if (line[i] != 0)
        {
            if (i != pos)
            {
                line[pos] = line[i];
                line[i] = 0;
            }
            pos++;
        }
    }
}

/**
 * slide_right - Déplace tous les nombres vers la droite
 * @line: Tableau d'entiers
 * @size: Taille du tableau
 */
static void slide_right(int *line, size_t size)
{
    size_t i;
    int pos = size - 1;
    
    for (i = size - 1; i < size; i--)
    {
        if (line[i] != 0)
        {
            if (i != (size_t)pos)
            {
                line[pos] = line[i];
                line[i] = 0;
            }
            pos--;
        }
    }
}

/**
 * slide_line - Fait glisser et fusionne une ligne de nombres
 * @line: Pointeur vers un tableau d'entiers
 * @size: Nombre d'éléments dans le tableau
 * @direction: Direction du glissement (SLIDE_LEFT ou SLIDE_RIGHT)
 * Return: 1 en cas de succès, 0 en cas d'échec
 */
int slide_line(int *line, size_t size, int direction)
{
    if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
        return (0);

    if (direction == SLIDE_LEFT)
    {
        slide_left(line, size);
        merge_left(line, size);
        slide_left(line, size);
    }
    else
    {
        slide_right(line, size);
        merge_right(line, size);
        slide_right(line, size);
    }

    return (1);
}
