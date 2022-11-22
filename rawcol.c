#include <stdio.h>
int main()
{
    int a[5][5] = {
        0,
    };
    a[0][1] = 2;
    a[1][0] = 3;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}