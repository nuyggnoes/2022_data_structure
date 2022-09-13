#include <stdio.h>
#include <string.h>
// a-z : 97-122
int main()
{
    char word1[20];
    char word2[20];
    int com1[27] = {0};
    int com2[27] = {0};
    int x = 0;
    scanf("%s", word1);
    scanf("%s", word2);
    for (int i = 0; i < strlen(word1); i++)
    {
        com1[word1[i] - 'a'] += 1;
    }
    for (int j = 0; j < strlen(word2); j++)
    {
        com2[word2[j] - 'a'] += 1;
    }
    for (int k = 0; k < 27; k++)
    {
        if ((com1[k] == 0 && com2[k] != 0) || (com1[k] != 0 && com2[k] == 0))
        {
            x++;
            break;
        }
    }
    // for (int k = 97; k < 123; k++)
    // {
    //     printf("%d ", com1[k]);
    // }
    // printf("\n");
    // for (int k = 97; k < 123; k++)
    // {
    //     printf("%d ", com2[k]);
    // }
    if (x > 0)
    {
        printf("no");
    }
    else
        printf("yes");
    return 0;
}