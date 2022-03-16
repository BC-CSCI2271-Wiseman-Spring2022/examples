#include <stdio.h>
#include <stdlib.h>
#include "int_list.h"

/* add new node to end of list */
void add_node(node **head, int value)
{
    node *new = (node *)malloc(sizeof(node));
    new->value = value;
    new->next = NULL;
    
    if (*head == NULL)
    {
        *head = new;
        return;
    }

    node *tmp = *head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = new;
}

/* print the whole list */
void print_list(node *head)
{
    for (node *tmp = head; tmp != NULL; tmp = tmp->next)
    {
        printf("%i ", tmp->value);
    }
    printf("\n");
}

/* free every node in the list */
void free_list(node **head)
{
    node *cur = *head;
    while (cur != NULL)
    {
        node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    *head = NULL;
}
