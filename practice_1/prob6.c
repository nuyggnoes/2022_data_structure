// 테스트 데이터를 모두 통과했습니다.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double prob(int N, int k)
{
    srand((unsigned int)time(NULL));

    int count2 = 0;
    for (int j = 0; j < 1000000; j++)
    {
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            int random = rand() % 6 + 1;
            if (random == 1)
            {
                count++;
            }
        }
        if (count >= k)
        {
            count2++;
        }
    }
    return count2;
}
int main(void)
{
    double ans;
    ans = prob(12, 2);
    printf("%f", ans / 1000000);
    return 0;
}