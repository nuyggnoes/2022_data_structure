#include <stdio.h>
int data[1000];
int cnt = 0;
int two_sum(int st, int end, int K)
{
    int sum = data[st] + data[end];
    if (st >= end)
        return cnt;
    else if (sum > K)
        two_sum(st, end - 1, K);
    else if (sum < K)
        two_sum(st + 1, end, K);
    else
    {
        cnt++;
        two_sum(st + 1, end - 1, K);
    }
    return cnt;
}
int main()
{
    int N, K;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &data[i]);
    }
    scanf("%d", &K);
    printf("%d", two_sum(0, N - 1, K));
    return 0;
}