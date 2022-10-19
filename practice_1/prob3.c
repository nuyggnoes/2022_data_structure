// 테스트 데이터를 모두 통과했습니다.
#include <stdio.h>
int main()
{
    int n, cnt = 0, m = 0;
    int data[100] = {-1};
    while (1)
    {
        scanf("%d", &n);
        if (n == -1)
            break;
        for (int i = 0; i < cnt; i++)
        {
            if (n == data[i])
                m++;
        }
        if (m == 0)
        {
            int i = cnt - 1;
            while (i >= 0 && data[i] > n)
            {
                data[i + 1] = data[i];
                i--;
            }
            data[i + 1] = n;
            cnt++;
            for (int i = 0; i < cnt; i++)
            {
                printf("%d ", data[i]);
            }
            printf("\n");
        }
        else
        {
            printf("duplicate\n");
            m = 0;
        }
    }
    return 0;
}