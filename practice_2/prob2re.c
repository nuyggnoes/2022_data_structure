#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main()
{
    FILE *fp = fopen("harry.txt", "r");
    char *data[10000];
    char buffer[40];
    int n = 0;
    while (fscanf(fp, "%s", buffer) != EOF)
    {
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (strcmp(buffer, data[i]) == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            int j = n - 1;
            while (j >= 0 && strcmp(buffer, data[j]) < 0)
            {
                data[j + 1] = data[j];
                j--;
            }
            data[j + 1] = strdup(buffer);
            n++;
        }
    }
    fclose(fp);
    char pre[40];
    scanf("%s", pre);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (strncmp(pre, data[i], strlen(pre)) == 0)
        {
            printf("%s\n", data[i]);
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}