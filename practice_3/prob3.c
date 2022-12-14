// 테스트 데이터를 모두 통과했습니다.
#include <stdio.h>
#include <string.h>
#define MAX 10000
int main()
{
    FILE *fp = fopen("shuffled_dict.txt", "r");
    char *word[MAX];
    char *word_exp[MAX];
    int idx, n = 0, i;
    if (fp == NULL)
    {
        return 0;
    }
    while (1)
    {
        char voca[100] = "";
        char exp[100] = "";
        char input[1000];
        char *pstr = fgets(input, 1000, fp);
        if (pstr == NULL)
        {
            break;
        }
        idx = 0;
        while (input[idx] != '\t')
        {
            voca[idx] = input[idx];
            idx++;
        }
        idx++;
        word[n] = strdup(voca);
        i = 0;
        while (idx != strlen(input))
        {

            exp[i] = input[idx];
            idx++;
            i++;
        }
        word_exp[n] = strdup(exp);
        n++;
    }
    fclose(fp);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (strcmp(word[j], word[j + 1]) > 0)
            {
                char *tmp1;
                char *tmp2;
                tmp1 = word[j];
                word[j] = word[j + 1];
                word[j + 1] = tmp1;
                tmp2 = word_exp[j];
                word_exp[j] = word_exp[j + 1];
                word_exp[j + 1] = tmp2;
            }
        }
    }
    FILE *fw = fopen("sorted_dict.txt", "w");
    for (int i = 0; i < n; i++)
    {
        fprintf(fw, "%s    %s", word[i], word_exp[i]);
    }
    fclose(fw);
    return 0;
}