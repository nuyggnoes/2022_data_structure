#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#define MAX 1000000
struct node
{
    Item data;
    struct node *next;
};
struct stack_type
{
    struct node *top;
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
        i = st->data;
        printf("%d ", i);
        st = st->next;
    }
}

int main()
{
    FILE *fp = fopen("input.txt", "r");
    int T, N;
    fscanf(fp, "%d", &T);
    Stack a;
    a = create();
    while (T > 0)
    {
        int cnt = 0, first, total = 0, sum = 0, pc = 0, prev = 0;
        fscanf(fp, "%d", &N);
        fscanf(fp, "%d", &first);
        push(a, first);
        // struct node *st;
        for (int i = 1; i < N; i++)
        {
            // st = a->top;
            int d;
            cnt = 0;
            fscanf(fp, "%d", &d);
            if (d < a->top->data)
            {
                push(a, d);
                cnt = 0;
                total = 0;
            }
            else
            {
                while (!is_empty(a))
                {
                    if (d < a->top->data)
                        break;
                    pop(a);
                    cnt++;
                    pc++;
                }
                if (is_empty(a))
                {
                    sum += pc;
                }
                else
                {
                    // total += cnt;
                    // sum += total;
                    prev += cnt;
                    sum += prev;
                }
                // printf("\n");
                push(a, d);
            }
            // printf("%d\n", pc);
            // list(a);
            // printf("\n");
            // printf("%d %d %d\n", cnt, prev, sum);
        }
        printf("%d\n", sum % MAX);
        // printf("%d\n", pc);
        T--;
        make_empty(a);
    }
    fclose(fp);
    return 0;
}