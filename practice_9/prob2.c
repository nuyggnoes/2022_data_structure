//테스트 데이터를 모두 통과했습니다.
#include <stdio.h>
#include <stdbool.h>
#include "queue.h"
#include "pos.h"
#define PATH 1
#define VISITED 2

int graph[50][50];
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
        Queue a = create();
        int cnt = 0;
        Position cur;
        cur.x = 0;
        cur.y = 0;
    A:
        enqueue(a, cur);
        if (graph[cur.x][cur.y] == PATH)
        {
            graph[cur.x][cur.y] = VISITED;
            cnt++;
        }
        while (!is_empty(a))
        {
            cur = dequeue(a);
            for (int i = 0; i < 8; i++)
            {
                Position n;
                n = move_to(cur, i);
                if (n.x < 0 || n.x >= N || n.y < 0 || n.y >= N)
                    continue;
                if (graph[n.x][n.y] == PATH)
                {
                    graph[n.x][n.y] = VISITED;
                    enqueue(a, n);
                    cnt++;
                }
            }
        }
        bool found = false;
        printf("%d ", cnt);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (graph[i][j] == PATH)
                {
                    found = true;
                    cur.x = i;
                    cur.y = j;
                    cnt = 0;
                    break;
                }
                if (found)
                    break;
                else if (i == N - 1 && j == N - 1)
                {
                    found = false;
                    break;
                }
            }
        }
        if (found)
            goto A;
        printf("\n");
        T--;
    }
    fclose(fp);
    return 0;
}