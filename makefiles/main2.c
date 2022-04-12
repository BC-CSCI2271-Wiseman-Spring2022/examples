#include <stdio.h>
#include <stdlib.h>
#include "int_list.h"

int main()
{
    node *head = NULL;

    add_node(&head, 16);
    add_node(&head, 8);
    add_node(&head, 32);
    add_node(&head, 4);
    add_node(&head, 128);

    print_list(head);
    free_list(&head);
    return 0;
}
