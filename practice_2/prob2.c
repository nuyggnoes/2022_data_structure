// 테스트 데이터를 모두 통과했습니다.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int main()
{
    char *word;
    char *data[100000];
    char tmp[MAX];
    char insert[MAX];

    FILE *fp = fopen("harry.txt", "r");
    int cnt = 0;
    for (cnt = 0; !feof(fp); cnt++)
    {
        word = (char *)malloc(sizeof(char) * MAX);
        fscanf(fp, "%s", word);
        data[cnt] = word;
    }
    cnt--;

    for (int i = 0; i < cnt; i++)
    {
        for (int j = i + 1; j < cnt; j++)
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
    while (idx <= cnt)
    {
        if (strcmp(data[idx], data[idx + 1]) == 0)
        {
            for (int i = idx + 1; i < cnt - 1; i++)
            {
                strcpy(data[i], data[i + 1]);
            }
            idx--;
            cnt--;
        }
        idx++;
    }
    int k = 0;
    scanf("%s", insert);

    for (int i = 0; i < cnt; i++)
    {
        if (strncmp(insert, data[i], strlen(insert)) == 0)
        {
            printf("%s\n", data[i]);
            k++;
        }
    }
    printf("%d", k);
    fclose(fp);
    return 0;
}