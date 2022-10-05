// 테스트 데이터를 모두 통과했습니다.
#include <stdio.h>
#include <string.h>
int main()
{
    char data[100];
    int len = 0, max = 0, idx = 0;
    scanf("%s", data);
    for (int i = 0; i < strlen(data); i++)
    {
        if (data[i] == 'a' || data[i] == 'e' || data[i] == 'i' || data[i] == 'o' || data[i] == 'u')
        {
            if (max < len)
            {
                max = len;
                idx = i;
            }
            len = 0;
        }
        else
        {
            len++;
            if (len < max)
                continue;
            else
            {
                idx = i;
                max = len;
            }
        }
    }
    for (int i = idx - max + 1; i < idx + 1; i++)
    {
        printf("%c", data[i]);
    }
    return 0;
}