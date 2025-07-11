#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * create_node - Creates a new node with the given string
 * @str: string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *create_node(char *str)
{
    List *new_node;
    char *new_str;

    if (!str)
        return (NULL);

    new_node = malloc(sizeof(List));
    if (!new_node)
        return (NULL);

    new_str = strdup(str);
    if (!new_str)
    {
        free(new_node);
        return (NULL);
    }

    new_node->str = new_str;
    new_node->prev = NULL;
    new_node->next = NULL;

    return (new_node);
}

/**
 * add_node_end - Adds a new node to the end of a double circular linked list
 * @list: pointer to the list to modify
 * @str: string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
    List *new_node, *last;

    if (!list)
        return (NULL);

    new_node = create_node(str);
    if (!new_node)
        return (NULL);

    if (!*list)
    {
        *list = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
        return (new_node);
    }

    last = (*list)->prev;
    new_node->next = *list;
    new_node->prev = last;
    last->next = new_node;
    (*list)->prev = new_node;

    return (new_node);
}

/**
 * add_node_begin - Adds a new node to the beginning of a double circular linked list
 * @list: pointer to the list to modify
 * @str: string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
    List *new_node;

    new_node = add_node_end(list, str);
    if (!new_node)
        return (NULL);

    if (*list != new_node)
        *list = new_node;

    return (new_node);
}
