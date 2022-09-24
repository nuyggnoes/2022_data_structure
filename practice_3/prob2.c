// 테스트 데이터를 모두 통과했습니다.
#include <stdio.h>
int main()
{
    int n, st, en, idx, tmp;
    int data_x[100];
    int data_y[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &st, &en);
        data_x[i] = st;
        data_y[i] = en;
    }

    for (int j = n - 1; j > 0; j--)
    {
        for (int k = 0; k < j; k++)
        {
            if (data_x[k] > data_x[k + 1])
            {
                tmp = data_x[k];
                data_x[k] = data_x[k + 1];
                data_x[k + 1] = tmp;
                tmp = data_y[k];
                data_y[k] = data_y[k + 1];
                data_y[k + 1] = tmp;
            }
            else if (data_x[k] == data_x[k + 1] && data_y[k] > data_y[k + 1])
            {
                tmp = data_y[k];
                data_y[k] = data_y[k + 1];
                data_y[k + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", data_x[i], data_y[i]);
    }
    return 0;
}
