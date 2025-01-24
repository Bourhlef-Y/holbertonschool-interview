#!/usr/bin/python3
"""
This module defines the function minOperations.
"""


def minOperations(n):
    """
    Calculate the minimum number of operations to result in exactly n H charac.
    """
    if n < 2:
        return 0

    operations = 0
    factor = 2

    while n > 1:
        while n % factor == 0:
            operations += factor
            n //= factor
        factor += 1

    return operations