#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

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

int main()
{
    node *head = NULL;

    add_node(&head, 16);
    add_node(&head, 8);
    add_node(&head, 32);
    add_node(&head, 4);

    print_list(head);
    free_list(&head);
    return 0;
}
