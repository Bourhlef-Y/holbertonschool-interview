#!/usr/bin/python3
"""
Module pour déterminer si toutes les boîtes peuvent être déverrouillées
"""


def canUnlockAll(boxes):
    """
    Détermine si toutes les boîtes peuvent être déverrouillées.

    Args:
        boxes (list): Liste de listes où chaque liste contient les clés

    Returns:
        bool: True si toutes les boîtes peuvent être ouvertes, False sinon
    """
    if not boxes or not isinstance(boxes, list):
        return False

    n = len(boxes)
    if n == 0:
        return True

    # Ensemble pour suivre les boîtes déverrouillées
    unlocked = {0}
    # Liste des clés disponibles à vérifier
    keys_to_check = boxes[0]

    # Tant qu'il y a des clés à vérifier
    while keys_to_check:
        key = keys_to_check.pop()

        # Vérifie si la clé est valide et si la boîte n'est pas déjà déverrouillée
        if isinstance(key, int) and 0 <= key < n and key not in unlocked:
            # Ajoute la boîte aux boîtes déverrouillées
            unlocked.add(key)
            # Ajoute les nouvelles clés à vérifier
            keys_to_check.extend(boxes[key])

    # Vérifie si toutes les boîtes ont été déverrouillées
    return len(unlocked) == n 