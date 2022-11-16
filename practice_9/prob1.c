#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include "stack.h"
// #include "pos.h"
#define PATH 1
#define VISITED 2
#define BACKTRACKED 3
// typedef int Item;
typedef struct stack_type *Stack;
typedef struct pos
{
    int x, y;
} Position;
Position move_to(Position pos, int dir);
Position pop(Stack s);
struct node
{
    Position data;
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
void push(Stack s, Position cur)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in push: stack is full.");
    new_node->data = cur;
    new_node->next = s->top;
    s->top = new_node;
}
Position pop(Stack s)
{
    struct node *old_top;
    Position i;

    if (is_empty(s))
        terminate("Error in pop: stack is empty.");
    old_top = s->top;
    i = old_top->data;
    s->top = old_top->next;
    free(old_top);
    return i;
}
Position peek(Stack s)
{
    if (is_empty(s))
        terminate("Error in peek: stack is empty.");
    return s->top->data;
}
// void list(Stack s)
// {
//     struct node *st;
//     Position i;
//     st = s->top;
//     while (st != NULL)
//     {
//         i = st->data;
//         printf("%d\n", i);
//         st = st->next;
//     }
// }
// typedef struct pos
// {
//     int x, y;
// } Position;
// Position move_to(Position pos, int dir);
int offset[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
Position move_to(Position pos, int dir)
{
    Position next;
    next.x = pos.x + offset[dir][0];
    next.y = pos.y + offset[dir][1];
    return next;
}
bool movable(Position pos, int dir)
{
    Position next;
    next.x = pos.x + offset[dir][0];
    next.y = pos.y + offset[dir][1];
    if (next.x < 0 || next.y < 0 || next.x != 1 || next.y != 1)
    {
        return false;
    }
    else
        return true;
}

int main()
{
    FILE *fp = fopen("input.txt", "r");
    int T, N;
    fscanf(fp, "%d", &T);
    while (T > 0)
    {
        fscanf(fp, "%d", &N);
        int com[50][50] = {
            0,
        };
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                fscanf(fp, "%d", &com[i][j]);
            }
        }
        int cnt = 0;
        Stack a = create();
        Position cur;
        cur.x = 0;
        cur.y = 0;
        while (1)
        {
            if (com[cur.x][cur.y] == 0)
            {
                cur.x = cur.x + 1;
                continue;
            }
            bool forwarded = false;
            for (int dir = 0; dir < 4; dir++)
            {
                if (movable(cur, dir))
                {
                    push(a, cur);
                    cnt++;
                    cur = move_to(cur, dir);
                    forwarded = true;
                    break;
                }
            }
            if (!forwarded)
            {
                com[cur.x][cur.y] = BACKTRACKED;
                if (is_empty(a))
                {
                    printf("No path exist\n");
                    break;
                }
                cur = pop(a);
            }
        }
        printf("%d ", cnt);
        T--;
    }
    fclose(fp);
    return 0;
}