#include <stdio.h>
#include <string.h>
int main()
{
    int n, max = 0, idx = 0, cnt = 0, k = 0;
    scanf("%d", &n);
    char *data[100];
    char word[20];
    char com[20];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", word);
        data[i] = strdup(word);
    }
    scanf("%s", com);
    while (n > 0)
    {
        cnt = 0;
        for (int i = 0; i < strlen(com); i++)
        {
            if (data[k][i] == com[i])
            {
                cnt++;
            }
            else
                break;
        }
        if (cnt > max)
        {
            max = cnt;
            idx = k;
        }
        k++;
        n--;
    }
    if (max == 0)
        printf("0");
    else
        printf("%s %d", data[idx], max);
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%s\n", data[i]);
    // }
    return 0;
}