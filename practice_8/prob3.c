#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

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
Stack create()
{
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL)
        terminate("Error in create: stack could not be created.");
    s->top = NULL;
    return s;
}
void destroy(Stack s)
{
    make_empty(s);
    free(s);
}
void make_empty(Stack s)
{
    while (!is_empty(s))
        pop(s);
}
bool is_empty(Stack s)
{
    return s->top == NULL;
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
        i = st->data;
        printf("%d ", i);
        st = st->next;
    }
}

int main()
{
    FILE *fp = fopen("input2.txt", "r");
    int T, N;
    fscanf(fp, "%d", &T);
    while (T > 0)
    {
        int cnt = 0, first = 0;
        Stack a = create();
        fscanf(fp, "%d", &N);
        fscanf(fp, "%d", &first);
        push(a, first);
        for (int i = 1; i < N; i++)
        {
            int d;
            fscanf(fp, "%d", &d);
            struct node *st;
            st = a->top;
            // printf("%d\n", st->data);
            printf("%d\n", d);
            while (d >= st->data)
            {
                pop(a);
                printf("%d\n", st->data);
                cnt++;
            }
            push(a, d);
        }
        list(a);
        printf("\n");
        printf("%d\n", cnt);
        destroy(a);
        T--;
    }
    fclose(fp);
    /*2
    7
    100 80 60 70 60 75 85 -> 100 80 70  <- 85
    8
    1 2 7 3 6 1 8 2*/

    /*3 7 2 4 6 9 8 3 1 7
    stack:
    3
    7
    7 2
    7 4
    7 6
    9
    9 8
    9 8 3
    9 8 3 1
    9 8 7
    */
}