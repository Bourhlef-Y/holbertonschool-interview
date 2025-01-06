#!/usr/bin/python3
"""lockboxes"""


def canUnlockAll(boxes):
    """
      Determines if all the boxes can be opened.
      Args:
          boxes: List of list
      Returns:
            True or false
      """
    n = len(boxes)
    open = [False] * n
    open[0] = True
    keys = boxes[0]

    while keys:
        key = keys.pop()
        if key < n and not open[key]:
            open[key] = True
            keys.extend(boxes[key])

    return all(open)