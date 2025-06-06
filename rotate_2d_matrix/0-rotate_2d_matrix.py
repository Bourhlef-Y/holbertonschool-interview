#!/usr/bin/python3
"""Module pour faire pivoter une matrice
2D de 90 degrés dans le sens horaire"""


def rotate_2d_matrix(matrix):
    """
    Fait pivoter une matrice 2D de n x n de 90 degrés dans le sens horaire
    Args:
        matrix: matrice 2D à faire pivoter
    """
    n = len(matrix)

    # Première étape : transposer la matrice
    for i in range(n):
        for j in range(i, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # Deuxième étape : inverser chaque ligne
    for i in range(n):
        matrix[i].reverse()
