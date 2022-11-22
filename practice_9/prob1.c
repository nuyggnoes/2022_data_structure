// 테스트 데이터를 모두 통과했습니다.
#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
#include "pos.h"
#define PATH 1
#define VISITED 2
int graph[50][50];
bool movable(Position pos)
{
    Position next;
    for (int i = 0; i < 8; i++)
    {
        next = move_to(pos, i);
        if (graph[next.x][next.y] == PATH)
            return true;
    }
    return false;
}
int main()
{
    FILE *fp = fopen("input.txt", "r");
    int T, N;
    fscanf(fp, "%d", &T);
    while (T > 0)
    {
        fscanf(fp, "%d", &N);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                fscanf(fp, "%d", &graph[i][j]);
            }
        }
        Stack a = create();
        int cnt = 0;
        Position cur;
        cur.x = 0;
        cur.y = 0;
        push(a, cur);
        while (1)
        {
            bool flag = false;
            for (int i = 0; i < 8; i++)
            {
                Position n;
                n = move_to(cur, i);
                if (n.x < 0 || n.x >= N || n.y < 0 || n.y >= N)
                    continue;
                if (graph[n.x][n.y] == PATH)
                {
                    graph[n.x][n.y] = VISITED;
                    push(a, n);
                    cnt++;
                    flag = true;
                    cur.x = n.x;
                    cur.y = n.y;
                    break;
                }
            }
            if (!flag)
            {
                if (!is_empty(a))
                {
                    cur = pop(a);
                    if (is_empty(a) && !movable(cur))
                    {
                        printf("%d ", cnt);
                        cnt = 0;
                    }
                }
                else
                {
                    cur.x += (cur.y + 1) / N;
                    cur.y = (cur.y + 1) % N;
                    if (cur.x == N - 1 && cur.y == N - 1)
                        break;
                }
            }
        }
        printf("\n");
        make_empty(a);
        T--;
    }
    fclose(fp);
    return 0;
}