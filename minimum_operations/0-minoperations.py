#!/usr/bin/python3
"""
Module that calculates minimum operations to achieve n H characters
"""


def minOperations(n):
    """
    Calculates the fewest number of operations needed to result in exactly n H
    characters in a file that can only be manipulated by Copy All and Paste
    operations.

    Args:
        n: Target number of H characters

    Returns:
        Integer representing minimum number of operations needed
        Returns 0 if n is impossible to achieve
    """
    if n <= 1:
        return 0

    operations = 0
    divisor = 2

    while n > 1:
        while n % divisor == 0:
            operations += divisor
            n = n // divisor
        divisor += 1

        # If divisor squared is greater than n, n is prime
        if divisor * divisor > n:
            if n > 1:
                operations += n
            break

    return operations
