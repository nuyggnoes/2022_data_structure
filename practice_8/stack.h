#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char *data;
    struct node *next;
} Node;
Node *top = NULL;

void push(char *item)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = item;
    p->next = top;
    top = p;
}
char *pop()
{
    if (is_empty())
        return NULL;
    char *result = top->data;
    top = top->next;
    return result;
}
char *peek()
{
    if (is_empty())
        return NULL;
    return top->data;
}
int is_empty()
{
    return top == NULL;
}