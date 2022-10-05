// 테스트 데이터를 모두 통과했습니다.
#include <stdio.h>
int count(int arr[][19], int x, int y, int dx, int dy, int n);
int main()
{
    FILE *fp = fopen("board.txt", "r");
    int board[19][19];
    int n;
    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(fp, "%d", &board[i][j]);
        }
    }
    int dx[4] = {1, 1, 0, 1};
    int dy[4] = {-1, 0, 1, 1};
    int nx, ny;
    int cnt1, cnt2;
    int winner = 0;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            if (board[x][y] == 1)
            {
                for (int k = 0; k < 4; k++)
                {
                    nx = x + dx[k];
                    ny = y + dy[k];
                    if (board[nx][ny] == 1)
                    {
                        cnt1 = count(board, x, y, dx[k], dy[k], 1);
                        if (cnt1 != 5)
                        {
                            cnt1 = 0;
                        }
                        else
                        {
                            winner = 1;
                            break;
                        }
                    }
                }
            }
            else if (board[x][y] == 2)
            {
                for (int k = 0; k < 4; k++)
                {
                    nx = x + dx[k];
                    ny = y + dy[k];
                    if (board[nx][ny] == 2)
                    {
                        cnt2 = count(board, x, y, dx[k], dy[k], 2);
                        if (cnt2 != 5)
                        {
                            cnt2 = 0;
                        }
                        else
                        {
                            winner = 2;
                            break;
                        }
                    }
                }
            }
        }
    }
    fclose(fp);
    if (winner == 0)
    {
        printf("Not Finished");
    }
    else if (winner == 2)
    {
        printf("White");
    }
    else if (winner == 1)
    {
        printf("Black");
    }
    return 0;
}
int count(int arr[][19], int x, int y, int dx, int dy, int n)
{
    int cnt = 0;
    while (arr[x][y] == n)
    {
        cnt++;
        x += dx;
        y += dy;
    }
    return cnt;
}