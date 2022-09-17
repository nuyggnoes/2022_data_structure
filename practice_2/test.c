#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define IDX 100

int main()
{
    char *word;
    char *data[100000];
    char tmp[IDX];
    char insert[IDX];

    FILE *fp = fopen("harry.txt", "r");
    int cnt = 0;

    if (fp == NULL)
    {
        fprintf(stderr, "File Open Error!\n");
        exit(1);
    }
    int a = 0;
    for (a = 0; !feof(fp); a++)
    {
        word = (char *)malloc(sizeof(char) * IDX);
        fscanf(fp, "%s", word);
        data[a] = word;
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
    while (idx <= a)
    {
        if (strcmp(data[idx], data[idx + 1]) == 0)
        {
            for (int i = idx + 1; i < a - 1; i++)
            {
                strcpy(data[i], data[i + 1]);
            }
            idx--;
            a--;
        }
        idx++;
    }
    int k = 0;
    scanf("%s", insert);

    for (int i = 0; i < a; i++)
    {
        if (strncmp(insert, data[i], strlen(insert)) == 0)
        {
            printf("%s\n", data[i]);
            k++;
        }
    }
    printf("%d", k);

    for (int i = 0; i < a; i++)
        free(data[i]);

    fclose(fp);

    return 0;
}
