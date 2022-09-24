// 테스트 데이터를 모두 통과했습니다.
#include <stdio.h>
int main()
{
    int n, idx = 0, cnt = 1, tmp;
    int data[100];
    scanf("%d", &n);
    while (cnt != n)
    {

        scanf("%d", &data[idx]);
        for (int i = 0; i < idx; i++)
        {
            if (data[idx] == data[i])
            {
                idx--;
                goto start;
            }
        }
        for (int j = idx; j > 0; j--)
        {
            if (data[j] < data[j - 1])
            {
                tmp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = tmp;
            }
        }
    start:
        idx++;
        cnt++;
    }
    printf("%d: ", idx);
    for (int i = 0; i < idx; i++)
    {
        printf("%d ", data[i]);
    }
    return 0;
}