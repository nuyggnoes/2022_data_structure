#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000
int main()
{
    FILE *fp = fopen("shuffled_dict.txt", "r");
    FILE *fw = fopen("sorted_dict.txt", "w");
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
        // word[n] = strdup(voca);
        i = 0;
        while (idx != strlen(input))
        {

            exp[i] = input[idx];
            idx++;
            i++;
        }
        // word_exp[n] = strdup(exp);
        int k = n - 1;
        while (k >= 0 && strcmp(voca, word[k]) < 0)
        {
            word[k + 1] = word[k];
            word_exp[k + 1] = word_exp[k];
            k--;
        }
        word[k + 1] = strdup(voca);
        word_exp[k + 1] = strdup(exp);
        n++;
    }
    fclose(fp);
    for (int i = 0; i < n; i++)
    {
        fprintf(fw, "%s    %s", word[i], word_exp[i]);
    }
    fclose(fw);
    return 0;
}