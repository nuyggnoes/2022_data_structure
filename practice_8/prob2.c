#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stackADT.h"
#define MAX 100
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include "stackADT.h"

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
    i = strdup(old_top->data);
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

int main()
{
    char input[MAX];
    char *data[5];
    int cnt = 0, k = 0;
    while (strcmp(input, "exit") != 0)
    {
        Stack a[10];
        int i = 0;
        printf("$");
        fgets(input, MAX, stdin);
        input[strlen(input) - 1] = '\0';
        char *ptr = strtok(input, " ");
        while (ptr != NULL)
        {
            data[i] = ptr;
            i++;
            ptr = strtok(NULL, " ");
        }
        if (strcmp(data[0], "create") == 0)
        {
            a[k] = create(data[1]);
            k++;
        }
        else if (strcmp(data[0], "push") == 0)
        {
            int ch;
            for (ch = 0; ch < k; ch++)
            {
                if (strcmp(a[ch]->name, data[1]) == 0)
                {
                    break;
                }
            }
            push(a[ch], strdup(data[2]));
        }
        else if (strcmp(data[0], "pop") == 0)
        {
            int ch;
            for (ch = 0; ch < k; ch++)
            {
                if (strcmp(a[ch]->name, data[1]) == 0)
                    break;
            }
            printf("%s\n", strdup(pop(a[ch])));
        }
        else if (strcmp(data[0], "list") == 0)
        {
            int ch;
            for (ch = 0; ch < k; ch++)
            {
                if (strcmp(a[ch]->name, data[1]) == 0)
                    break;
            }
            list(a[ch]);
        }
    }
    return 0;
}