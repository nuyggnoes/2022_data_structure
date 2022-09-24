// 테스트 데이터를 모두 통과했습니다.
#include <stdio.h>
int main()
{
    int n, input, max, tmp, idx = 0;
    int data[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input);
        data[i] = input;
    }
    max = data[0];
    int cnt = n;
    while (cnt > 0)
    {
        max = data[0];
        for (int k = 0; k < cnt; k++)
        {
            if (data[k] >= max)
            {
                max = data[k];
                idx = k;
            }
        }
        tmp = data[idx];
        data[idx] = data[cnt - 1];
        data[cnt - 1] = tmp;
        cnt--;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }
    return 0;
}
