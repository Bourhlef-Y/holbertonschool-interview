#!/usr/bin/python3
"""
Module pour calculer l'eau retenue entre les murs
"""


def rain(walls):
    """
    Calcule la quantité d'eau retenue après la pluie
    Args:
        walls: liste d'entiers non-négatifs représentant la hauteur des murs
    Returns:
        quantité totale d'eau retenue
    """
    if not walls:
        return 0
    
    n = len(walls)
    eau_totale = 0
    
    # Pour chaque position, trouver le max à gauche et à droite
    for i in range(1, n - 1):
        # Trouver le mur le plus haut à gauche
        gauche_max = max(walls[:i])
        
        # Trouver le mur le plus haut à droite
        droite_max = max(walls[i + 1:])
        
        # Le niveau d'eau est déterminé par le plus petit des deux murs max
        niveau_eau = min(gauche_max, droite_max)
        
        # Si le niveau d'eau est plus haut que le mur actuel, l'eau est retenue
        if niveau_eau > walls[i]:
            eau_totale += niveau_eau - walls[i]
    
    return eau_totale 