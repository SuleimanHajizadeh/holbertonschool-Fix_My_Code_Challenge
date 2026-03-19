#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a doubly linked list
 *
 * @head: A pointer to the pointer to the first element of the list
 * @index: The index of the node to delete (0-based)
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *tmp;
    unsigned int i;

    if (!head || !*head)
        return (-1);

    tmp = *head;
    i = 0;

    /* traverse to the node to delete */
    while (tmp && i < index)
    {
        tmp = tmp->next;
        i++;
    }

    /* if index is out of range */
    if (!tmp)
        return (-1);

    /* fix previous node's next pointer */
    if (tmp->prev)
        tmp->prev->next = tmp->next;
    else
        *head = tmp->next; /* deleting the head node */

    /* fix next node's prev pointer */
    if (tmp->next)
        tmp->next->prev = tmp->prev;

    free(tmp);
    return (1);
}

