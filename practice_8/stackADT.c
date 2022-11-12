#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stackADT.h"

struct node
{
    Item data;
    struct node *next;
};
struct stack_type
{
    struct node *top;
    char *name;
};
static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}
Stack create(char *name)
{
    Stack s = malloc(sizeof(struct stack_type));
    s->name = strdup(name);
    if (s == NULL)
        terminate("Error in create: stack could not be created.");
    s->top = NULL;
    return s;
}
bool is_empty(Stack s)
{
    return s->top == NULL;
}
void make_empty(Stack s)
{
    while (!is_empty(s))
        pop(s);
}
void destroy(Stack s)
{
    make_empty(s);
    free(s);
}
void push(Stack s, Item i)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in push: stack is full.");
    new_node->data = i;
    new_node->next = s->top;
    s->top = new_node;
}
Item pop(Stack s)
{
    struct node *old_top;
    Item i;

    if (is_empty(s))
        terminate("Error in pop: stack is empty.");
    old_top = s->top;
    i = old_top->data;
    s->top = old_top->next;
    free(old_top);
    return i;
}
Item peek(Stack s)
{
    if (is_empty(s))
        terminate("Error in peek: stack is empty.");
    return s->top->data;
}
void list(Stack s)
{
    struct node *st;
    Item i;
    st = s->top;
    while (st != NULL)
    {
        i = strdup(st->data);
        printf("%s\n", i);
        st = st->next;
    }
}