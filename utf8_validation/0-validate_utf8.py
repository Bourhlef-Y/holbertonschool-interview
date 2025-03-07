#!/usr/bin/python3
"""Module pour valider l'encodage UTF-8"""


def validUTF8(data):
    """
    Détermine si une liste de données représente un encodage UTF-8 valide
    Args:
        data: Liste d'entiers représentant les octets
    Returns:
        bool: True si l'encodage est valide, False sinon
    """
    # Nombre d'octets restants à vérifier pour le caractère en cours
    remaining_bytes = 0

    # Masques binaires pour la vérification
    mask1 = 1 << 7  # 10000000
    mask2 = 1 << 6  # 01000000

    for byte in data:
        # Ne considérer que les 8 bits les moins significatifs
        byte = byte & 255

        # Si nous ne sommes pas en train de vérifier un caractère multi-octets
        if remaining_bytes == 0:
            # Compter le nombre d'octets pour ce caractère
            mask = 1 << 7
            while byte & mask:
                remaining_bytes += 1
                mask = mask >> 1

            # Pour un octet simple, remaining_bytes doit être 0
            # Pour un char multi-octets, remaining_bytes doit être entre 2 et 4
            if remaining_bytes == 0:
                continue
            if remaining_bytes == 1 or remaining_bytes > 4:
                return False

            # Ajuster car nous avons déjà traité le premier octet
            remaining_bytes -= 1
        else:
            # Vérifier que l'octet commence par 10
            if not (byte & mask1 and not (byte & mask2)):
                return False
            remaining_bytes -= 1

    # Tous les caractères doivent être complets
    return remaining_bytes == 0
