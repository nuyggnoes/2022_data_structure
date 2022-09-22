#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *a[100000]; //단어 저장
char *b[100000]; //뜻 저장
int main(void)
{
    char word[100000];
    char *ptr;
    int end = 0, i = 0;
    char temp[100];

    FILE *fp = fopen("shuffled_dick.txt", "r");
    if (fp == NULL)
    {
        return 0;
    }
    while (1)
    {
        char *pstr = fgets(word, 100000, fp); // word[n]에 한 줄 씩 저장
        if (pstr == NULL)
        {
            break;
        }
        ptr = strtok(word, "    "); // 1줄 씩 \t가 나올 때 까지 짜름
        while (ptr != NULL)
        {
            printf("%s\n", ptr);
            strtok(NULL, "");
        }
    }

    // for (int i = 0; i < end; i++)
    // {
    //     for (int j = i + 1; j < end; j++)
    //     {
    //         if (strcmp(a[i], a[j]) > 0)
    //         {
    //             strcpy(temp, a[i]);
    //             strcpy(a[i], a[j]);
    //             strcpy(a[j], temp);
    //             strcpy(temp, b[i]);
    //             strcpy(b[i], b[j]);
    //             strcpy(b[j], temp);
    //         }
    //     }
    // }

    // for (int i = 0; i < end; i++)
    // {
    //     printf("%s\t%s", a[i], b[i]);
    // }
}