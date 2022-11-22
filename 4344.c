#pragma warning(disable : 4996)

#include <stdio.h>

int main()
{
    int C, N;
    float av = 0, cnt = 0;
    int S[1000];
    scanf("%d", &C);
    for (int i = 0; i < C; i++)
    {
        scanf("%d", &N);
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &S[j]);
            av += S[j];
        }
        av = av / N;
        for (int j = 0; j < N; j++)
        {
            if (S[j] > av)
                cnt++;
        }
        printf("%.3f", (cnt / N) * 100);
        printf("%%\n");
        av = 0;
        cnt = 0;
    }
    return 0;
}