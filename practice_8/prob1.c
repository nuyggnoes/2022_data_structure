#include <stdio.h>
#include <string.h>
#define MAX 100
int main()
{
    char data[MAX];
    int cnt[MAX / 2];
    scanf("%s", data);
    int idx = 0, i = 0, d = 1;
    while (idx < strlen(data))
    {
        if (data[idx] == '(')
        {
            cnt[i] = d++;
            printf("%d ", cnt[i]);
            i++;
        }
        else if (data[idx] == ')')
        {
            printf("%d ", cnt[--i]);
        }
        idx++;
    }
    return 0;
}