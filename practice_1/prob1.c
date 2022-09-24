// 테스트 데이터를 모두 통과했습니다.
#include <stdio.h>
int main()
{
    int num;
    scanf("%d", &num);
    while (num != 0)
    {
        num /= 2;
        printf("%d ", num);
    }
    return 0;
}