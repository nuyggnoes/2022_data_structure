#include <stdio.h>
#include <string.h>
#define LENGTH 1000
char *t[100][100];
int main()
{
    FILE *fp = fopen("table.txt", "r");
    FILE *fw = fopen("output.txt", "w");
    int m, n;
    char str[LENGTH];
    if (fp == NULL)
    {
        return 0;
    }
    fscanf(fp, "%d %d", &m, &n);
    int i = 0, j = 0;
    while (fgets(str, LENGTH, fp) != NULL)
    {
        if (str[strlen(str) - 1] == '\n')
        {
            str[strlen(str) - 1] = '\0';
        }
        if (strlen(str) <= 0)
            continue;
        char *ptr = strtok(str, "&");
        while (ptr != NULL)
        {
            t[i][j++] = strdup(ptr);
            ptr = strtok(NULL, "&");
        }
        j = 0;
        i++;
    }
    fclose(fp);
    int cnt[10];
    int max, len;
    // for (int i = 0; i < m; i++)
    // {
    //     max = -1;
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (strlen(t[j][i]) >= max)
    //         {
    //             max = strlen(t[j][i]);
    //         }
    //     }
    //     cnt[i] = max;
    // }
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
            cnt[i] = t[j][i];
        }
    }
    fclose(fw);
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", strlen(t[i][0]));
    // }
    return 0;
}