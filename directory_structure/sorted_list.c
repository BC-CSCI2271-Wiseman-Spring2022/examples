#include "sorted_list.h"

/* add new node to list in sorted order*/
void add_node(node **head, char *value)
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
    if (strcmp(tmp->value, value) > 0)
    {
        new->next = tmp;
        *head = new;
        return;
    }

    while (tmp->next != NULL)
    {
        if (strcmp(tmp->next->value, value) > 0)
        {
            new->next = tmp->next;
            tmp->next = new;
            return;
        }
        tmp = tmp->next;
    }
    tmp->next = new;
}

/* free every node in the list */
void free_list(node **head)
{
    node *cur = *head;
    while (cur != NULL)
    {
        node *tmp = cur;
        cur = cur->next;
        free(tmp->value);
        free(tmp);
    }
    *head = NULL;
}

