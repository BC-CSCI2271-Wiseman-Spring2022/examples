#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

node *head = NULL;

/* add new node to end of list */
void add_node(int value)
{
    node *new = (node *)malloc(sizeof(node));
    new->value = value;
    new->next = NULL;
    
    if (head == NULL)
    {
        head = new;
        return;
    }

    node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = new;
}

/* print the whole list */
void print_list()
{
    for (node *tmp = head; tmp != NULL; tmp = tmp->next)
    {
        printf("%i ", tmp->value);
    }
    printf("\n");
}

int main()
{
    add_node(16);
    add_node(8);
    add_node(32);
    add_node(4);

    print_list();
    return 0;
}
