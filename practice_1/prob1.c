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