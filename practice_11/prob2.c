#include <stdio.h>
int miro[50][50];
int main()
{
    FILE *fp = fopen("miro.txt", "r");
    int N;
    fscanf(fp, "%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            fscanf(fp, "%d", &miro[i][j]);
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", miro[i][j]);
        }
        printf("\n");
    }
    return 0;
}