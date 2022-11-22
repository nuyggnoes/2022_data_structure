#include <stdio.h>
int data[1000];
int N;
int ffloor(int end, int K)
{
    if (data[0] > K)
        return -1;
    else if (data[end] <= K)
        return data[end];
    else
    {
        return ffloor(end - 1, K);
    }
}
int ceiling(int st, int K)
{
    if (data[N - 1] < K)
        return -1;
    else if (data[st] >= K)
        return data[st];
    else
        return ceiling(st + 1, K);
}
int main()
{
    int K;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &data[i]);
    }
    scanf("%d", &K);
    printf("%d\n", ffloor(N - 1, K));
    printf("%d", ceiling(0, K));
    return 0;
}