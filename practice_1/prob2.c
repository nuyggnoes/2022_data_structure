// 테스트 데이터를 모두 통과했습니다.
#include <stdio.h>
void BubbleSort();
int main()
{
    int n;
    int data[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }
    BubbleSort(data, n);
    printf("%d %d", data[0], data[1]);
    return 0;
}
void BubbleSort(int list[], int x) // 버블 정렬
{
    int temp;

    for (int i = x - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (list[j] > list[j + 1])
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}