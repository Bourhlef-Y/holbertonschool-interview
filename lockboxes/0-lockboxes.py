#!/usr/bin/python3
"""Module pour déterminer si toutes les boîtes peuvent être déverrouillées."""


def canUnlockAll(boxes):
    """Détermine si toutes les boîtes peuvent être déverrouillées.

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

    # Set to track unlocked boxes
    unlocked = {0}
    # List of available keys to check
    keys_to_check = boxes[0]

    # While there are keys to check
    while keys_to_check:
        key = keys_to_check.pop()

        # Check if key is valid and box is not already unlocked
        if isinstance(key, int) and 0 <= key < n and key not in unlocked:
            # Add box to unlocked boxes
            unlocked.add(key)
            # Add new keys to check
            keys_to_check.extend(boxes[key])

    # Check if all boxes have been unlocked
    return len(unlocked) == n
