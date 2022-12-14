// 테스트 데이터를 모두 통과했습니다.
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
int count(Stack s, int n);
int main()
{
    int T;
    FILE *fp = fopen("input.txt", "r");
    fscanf(fp, "%d", &T);

    for (int t = 0; t < T; t++)
    {
        int N;
        int n;
        long long answer = 0;
        Stack s1 = create();
        fscanf(fp, "%d", &N);

        for (int i = 0; i < N; i++)
        {
            fscanf(fp, "%d", &n);
            answer += count(s1, n);
            push(s1, n);
        }

        printf("%lld\n", answer % 1000000);

        destroy(s1);
    }
    fclose(fp);
}
int count(Stack s, int top_data)
{
    Stack s_tmp = create();
    int cnt = 0;
    while (!is_empty(s) && peek(s) <= top_data)
    {
        push(s_tmp, pop(s));
        cnt++;
    }
    while (!is_empty(s_tmp))
    {
        push(s, pop(s_tmp));
    }
    destroy(s_tmp);
    return cnt;
}