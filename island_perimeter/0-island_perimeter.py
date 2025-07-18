#!/usr/bin/python3
"""
Module qui calcule le périmètre d'une île dans une grille
"""


def island_perimeter(grid):
    """
    Calcule le périmètre d'une île dans une grille
    Args:
        grid: liste de listes d'entiers représentant l'île
    Returns:
        périmètre de l'île
    """
    if not grid:
        return 0

    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                # Ajoute 4 au périmètre pour chaque cellule terrestre
                perimeter += 4

                # Vérifie la cellule au-dessus
                if i > 0 and grid[i - 1][j] == 1:
                    # Soustrait 2 car les côtés se touchent
                    perimeter -= 2

                # Vérifie la cellule à gauche
                if j > 0 and grid[i][j - 1] == 1:
                    # Soustrait 2 car les côtés se touchent
                    perimeter -= 2

    return perimeter
