// 테스트 데이터를 모두 통과했습니다.
#include <stdio.h>
#include <string.h>
#define LENGTH 1000
char *t[100][100];
char *space_delete(char *arr); //공백 제거 함수
int main()
{
    FILE *fp = fopen("table.txt", "r");
    FILE *fw = fopen("output.txt", "w");
    int m, n;
    char buf[LENGTH];
    if (fp == NULL)
    {
        return 0;
    }
    fscanf(fp, "%d %d ", &m, &n);
    int i = 0, j = 0;
    while (fgets(buf, LENGTH, fp) != NULL)
    {
        if (buf[strlen(buf) - 1] == '\n')
        {
            buf[strlen(buf) - 1] = '\0';
        }
        if (strlen(buf) <= 0)
            continue;
        char *ptr = strtok(buf, "&");
        while (ptr != NULL)
        {
            ptr = space_delete(ptr);
            t[i][j++] = strdup(ptr);
            ptr = strtok(NULL, "&");
        }
        j = 0;
        i++;
    }
    fclose(fp);
    int cnt[10];
    int max, len;
    for (int i = 0; i < m; i++)
    {
        max = -1;
        len = 0;
        for (int j = 0; j < n; j++)
        {
            len = strlen(t[j][i]);
            if (len > max)
            {
                max = len;
            }
        }
        cnt[i] = max;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int len = cnt[j] - strlen(t[i][j]);
            fprintf(fw, "%s", t[i][j]);
            while (len > 0)
            {
                fprintf(fw, " ");
                len--;
            }
        }
        fprintf(fw, "\n");
    }
    fclose(fw);
    return 0;
}
char *space_delete(char *arr) //공백 제거 함수
{
    while (*arr == ' ')
        arr++;
    int idx = strlen(arr);
    for (int k = idx; k > 0; k--)
    {
        if (arr[k] == ' ' && arr[k - 1] == ' ')
        {
            for (int i = k; i < idx; i++)
            {
                arr[i] = arr[i + 1];
            }
        }
    }
    return arr;
}
