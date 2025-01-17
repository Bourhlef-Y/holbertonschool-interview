#include "lists.h"

/**
 * insert_node - Insère un nombre dans une liste chaînée triée
 * @head: pointeur vers le pointeur de tête de la liste
 * @number: nombre à insérer
 * Return: adresse du nouveau nœud ou NULL si échec
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *nouveau = malloc(sizeof(listint_t));
    listint_t *actuel;

    if (nouveau == NULL)
        return (NULL);

    nouveau->n = number;
    nouveau->next = NULL;

    /* Si la liste est vide ou si number est plus petit que la tête */
    if (*head == NULL || (*head)->n >= number)
    {
        nouveau->next = *head;
        *head = nouveau;
        return (nouveau);
    }

    /* Parcourir la liste jusqu'au bon point d'insertion */
    actuel = *head;
    while (actuel->next != NULL && actuel->next->n < number)
        actuel = actuel->next;

    /* Insérer le nouveau nœud */
    nouveau->next = actuel->next;
    actuel->next = nouveau;

    return (nouveau);
} 