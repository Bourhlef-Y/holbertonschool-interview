#!/usr/bin/python3
"""Module to determine if all boxes can be unlocked."""


def can_unlock_all(boxes):
    """Determine if all boxes can be unlocked.

    Args:
        boxes (list): List of lists where each list contains keys

    Returns:
        bool: True if all boxes can be opened, False otherwise
    """
    if not boxes or not isinstance(boxes, list):
        return False

    n = len(boxes)
    if n == 0:
        return True

    # Set to track unlocked boxes
    unlocked = {0}
    # List of keys to check
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
