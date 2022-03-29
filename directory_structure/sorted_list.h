#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char *value;
    struct node *next;
} node;

/* add new node to list in sorted order */
void add_node(node **head, char *value);

/* free every node in the list */
void free_list(node **head);
