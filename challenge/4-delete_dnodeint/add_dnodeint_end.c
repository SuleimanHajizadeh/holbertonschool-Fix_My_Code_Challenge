#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - Add a node at the end of a doubly linked list
 *
 * @head: The address of the pointer to the first element of the list
 * @n: The integer value to store in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *new_node;
    dlistint_t *tmp;

    new_node = malloc(sizeof(dlistint_t));
    if (!new_node)
        return (NULL);

    new_node->n = n;
    new_node->next = NULL;

    if (!*head)
    {
        new_node->prev = NULL;
        *head = new_node;
        return (new_node);
    }

    tmp = *head;
    while (tmp->next)
        tmp = tmp->next;

    tmp->next = new_node;
    new_node->prev = tmp;

    return (new_node);
}

