#!/usr/bin/python3
"""
Module pour compter les occurrences de mots-clés dans les titres
des articles Reddit
"""
import requests


def count_words(subreddit, word_list, after=None, word_count=None):
    """
    Fonction récursive qui compte les occurrences de mots-clés dans les titres
    des articles Reddit.

    Args:
        subreddit: Le subreddit à analyser
        word_list: Liste des mots-clés à chercher
        after: Token pour la pagination
        word_count: Dictionnaire pour stocker le compte des mots

    Returns:
        None (imprime les résultats)
    """
    # Initialisation du dictionnaire de comptage
    if word_count is None:
        word_count = {}
        for word in word_list:
            word = word.lower()
            if word not in word_count:
                word_count[word] = 0

    # URL de l'API Reddit
    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {'User-Agent': 'Mozilla/5.0'}
    params = {'limit': 100}

    if after:
        params['after'] = after

    try:
        response = requests.get(
            url,
            headers=headers,
            params=params,
            allow_redirects=False
        )

        # Vérification de la validité du subreddit
        if response.status_code != 200:
            return

        data = response.json()
        posts = data['data']['children']

        # Analyse des titres
        for post in posts:
            title_words = post['data']['title'].lower().split()

            # Compte les occurrences des mots-clés
            for word in title_words:
                for search_word in word_count:
                    if word == search_word:
                        word_count[search_word] += 1

        # Récursion si plus de posts
        after = data['data']['after']
        if after:
            count_words(subreddit, word_list, after, word_count)
        else:
            # Trie et affiche les résultats
            sorted_counts = sorted(
                word_count.items(),
                key=lambda x: (-x[1], x[0])
            )

            for word, count in sorted_counts:
                if count > 0:
                    print(f"{word}: {count}")

    except Exception:
        return
