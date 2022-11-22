#include <stdio.h>
#include <string.h>
int main()
{
    char word[20];
    char *data[100];
    char tmp[20];
    int flag = 0, cnt = 0, idx = 0;
    while (1)
    {
        flag = 0;
        scanf("%s", word);
        if (strcmp(word, "exit") == 0)
            return 0;
        int i = cnt - 1;
        while (i >= 0 && strlen(data[i]) >= strlen(word))
        {
            flag = 1;
            data[i + 1] = data[i];
            i--;
        }
        data[i + 1] = strdup(word);
        for (int k = 0; k < cnt; k++)
        {
            if (strlen(data[k]) == strlen(data[k + 1]))
            {
                if (strcmp(data[k], data[k + 1]) > 0)
                {
                    strcpy(tmp, data[k]);
                    strcpy(data[k], data[k + 1]);
                    strcpy(data[k + 1], data[k]);
                }
            }
        }
        if (flag == 0)
            data[i + 1] = strdup(word);
        for (int j = 0; j <= cnt; j++)
        {
            printf("%s ", data[j]);
        }
        printf("\n");
        cnt++;
    }
}