#include <stdio.h>
#include <string.h>
#define MAX 10000
int main()
{
    FILE *fp = fopen("shuffled_dict.txt", "r");
    char *word[MAX];
    char *word_exp[MAX];
    int n = 0;
    if (fp == NULL)
    {
        return 0;
    }
    while (1)
    {
        char tap = '\t';
        char enter = '\n';
        char *token;
        char input[1000];
        char *pstr = fgets(input, 1000, fp);
        if (pstr == NULL)
        {
            break;
        }
        token = strtok(input, &tap);
        word[n] = strdup(token);
        token = strtok(NULL, &enter);
        word_exp[n] = strdup(token);
        n++;
    }
    fclose(fp);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
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
    FILE *fw = fopen("sorted_dict2.txt", "w");
    for (int i = 0; i < n; i++)
    {
        fprintf(fw, "%s    %s\n", word[i], word_exp[i]);
    }
    fclose(fw);
    return 0;
}