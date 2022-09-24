// 테스트 데이터를 모두 통과했습니다.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
    int a_len;
    int b_len;
    a_len = strlen(a);
    b_len = strlen(b);
    if (a_len == b_len)
    {
        return strcmp((char *)a, (char *)b);
    }
    else if (a_len > b_len)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    if (N < 1 || N > 20000)
    {
        return -1;
    }
    char str[N][51];
    for (int i = 0; i < N; i++)
    {
        scanf("%s", str[i]);
    }
    qsort(str, N, sizeof(str[0]), compare);
    for (int i = 0; i < N; i++)
    {
        if (strcmp(str[i], str[i + 1]) == 0)
        {
            continue;
        }
        printf("%s\n", str[i]);
    }

    return 0;
}
