// 테스트 데이터를 모두 통과했습니다.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int main()
{
    FILE *fp = fopen("harry.txt", "r");
    char word[100];
    char *data[100000];
    char tmp[MAX];
    int a = 0;
    while (!feof(fp))
    {
        // word = (char *)malloc(sizeof(char) * MAX);
        fscanf(fp, "%s", word);
        if (strlen(word) >= 6)
        {
            data[a] = strdup(word);
            a++;
        }
    }
    a--;

    for (int i = 0; i < a; i++)
    {
        for (int j = i + 1; j < a; j++)
        {
            if (strcmp(data[i], data[j]) > 0)
            {
                strcpy(tmp, data[i]);
                strcpy(data[i], data[j]);
                strcpy(data[j], tmp);
            }
        }
    }

    int idx = 0;
    int idx2 = 0;
    int cnt = 0;
    while (idx < a)
    {
        int cnt2 = 1;
        idx2 = idx + 1;
        if (strcmp(data[idx], data[idx2]) == 0)
        {
            while (strcmp(data[idx], data[idx2]) == 0)
            {
                cnt2++;
                idx2++;
            }
        }
        printf("%s: %d\n", data[idx], cnt2);
        idx = idx2;
        cnt++;
    }
    printf("%d", cnt);
    fclose(fp);
    return 0;
}
