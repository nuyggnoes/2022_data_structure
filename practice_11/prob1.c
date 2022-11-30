#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int count = 0;
int n;
int board[15];

bool promising(int cdx)
{
    for (int i = 0; i < cdx; i++)
        if (board[cdx] == board[i] || cdx - i == abs(board[cdx] - board[i]))
            return false;
    return true;
}
void nqueen(int cdx)
{

    if (cdx == n)
    {
        count++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        board[cdx] = i;
        if (promising(cdx))
        {
            nqueen(cdx + 1);
        }
    }
}
int main()
{
    scanf("%d", &n);
    nqueen(0);
    printf("%d\n", count);
    // for (int i = 1; i < 11; i++)
    // {
    //     printf("%d - queen : %d", i, count);
    // }
}