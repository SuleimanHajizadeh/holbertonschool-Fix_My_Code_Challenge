#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    dlistint_t *head;

    head = NULL;

    /* Add nodes */
    add_dnodeint_end(&head, 0);
    add_dnodeint_end(&head, 1);
    add_dnodeint_end(&head, 2);
    add_dnodeint_end(&head, 3);
    add_dnodeint_end(&head, 4);
    add_dnodeint_end(&head, 98);
    add_dnodeint_end(&head, 402);
    add_dnodeint_end(&head, 1024);

    /* Print list */
    print_dlistint(head);
    printf("-----------------\n");

    /* Delete nodes at specific indices */
    delete_dnodeint_at_index(&head, 5); /* delete 98 */
    print_dlistint(head);
    printf("-----------------\n");

    delete_dnodeint_at_index(&head, 0); /* delete head */
    print_dlistint(head);
    printf("-----------------\n");

    /* Delete remaining nodes one by one */
    while (head)
    {
        delete_dnodeint_at_index(&head, 0);
        print_dlistint(head);
        printf("-----------------\n");
    }

    /* Free the list */
    free_dlistint(head);

    return (0);
}

