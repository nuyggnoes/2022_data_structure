#include <stdio.h>
int graph[50][50];
int apart[50 * 50];
int n, count, sum;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dfs(int x, int y);
void reset();
typedef struct pos
{
    int x, y;
} Position;
int main()
{
    FILE *fp = fopen("input.txt", "r");
    int T, N;
    fscanf(fp, "%d", &T);
    while (T > 0)
    {
        fscanf(fp, "%d", &N);
        int graph[50][50] = {
            0,
        };
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                fscanf(fp, "%d", &graph[i][j]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dfs(i, j) == 1)
                {
                    apart[count]++;
                    count = 0;
                    sum++;
                }
            }
        }
        printf("%d\n", sum);
        for (int i = 0; i < 26 * 26; i++)
        {
            if (apart[i] != 0)
            {
                int k = apart[i];
                for (int j = 0; j < k; j++)
                {
                    printf("%d\n", i);
                }
            }
        }
        return 0;
    }
}
// void BFS(int i, int j, int num)
// {
//     graph[i][j] = 2;
//     q.push(pair<int, int>(i, j));
//     while (!q.empty())
//     {
//         i = q.front().first;
//         j = q.front().second;
//         q.pop();
//         for (int d = 0; d < 4; d++)
//         {
//             int ni = i + dir[d][0];
//             int nj = j + dir[d][1];
//             if ((ni >= 0 && nj >= 0) && (ni < N && nj < N))
//             {
//                 if (map[ni][nj] && !visited[ni][nj])
//                 {
//                     visited[ni][nj] = 1;
//                     q.push(pair<int, int>(ni, nj));
//                     num++;
//                 }
//             }
//         }
//     }
//     v.push_back(num);
// }

// int bfs(int x, int y)
// {
//     if (x < 0 || y < 0 || x >= n || y >= n)
//     {
//         return 0;
//     }

//     if (graph[x][y] == 1)
//     {
//         graph[x][y] = 0;
//         count++;

//         for (int i = 0; i < 4; i++)
//         {
//             dfs(x + dx[i], y + dy[i]);
//         }
//         return 1;
//     }
//     return 0;
// }