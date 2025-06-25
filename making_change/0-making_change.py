#!/usr/bin/python3
"""
Module pour résoudre le problème de rendu de monnaie
"""


def makeChange(coins, total):
    """
    Détermine le nombre minimum de pièces
    nécessaires pour atteindre un total donné

    Args:
        coins: liste des valeurs des pièces disponibles
        total: montant total à atteindre

    Returns:
        Nombre minimum de pièces nécessaires, ou -1 si impossible
    """
    if total <= 0:
        return 0

    # Initialiser le tableau de programmation dynamique
    # dp[i] représente le nombre minimum de pièces pour faire le montant i
    dp = [float('inf')] * (total + 1)
    dp[0] = 0  # 0 pièce nécessaire pour faire 0

    # Pour chaque montant de 1 à total
    for amount in range(1, total + 1):
        # Essayer chaque pièce
        for coin in coins:
            if coin <= amount:
                dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    # Si dp[total] est encore infini, c'est impossible
    return dp[total] if dp[total] != float('inf') else -1
