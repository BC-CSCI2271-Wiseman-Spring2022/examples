typedef struct node
{
    int value;
    struct node *next;
} node;

/* add new node to end of list */
void add_node(node **head, int value);

/* print the whole list */
void print_list(node *head);

/* free every node in the list */
void free_list(node **head);
