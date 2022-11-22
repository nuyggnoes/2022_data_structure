#include <stdio.h>

typedef struct node
{
    char *data;
    struct node *next;
    struct node *prev;
} Node;

Node *head;
Node *tail;
int size = 0;
void add_after(Node *pre, char *item)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = item;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (pre == NULL && head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else if (pre == NULL)
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    else if (pre == tail)
    {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
}