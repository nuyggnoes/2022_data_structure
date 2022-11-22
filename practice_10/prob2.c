#include <stdio.h>
#include <string.h>
int idx = 0;
int compare(char *str1, char *str2)
{
    if (strlen(str1) == idx - 1)
        return 0;
    else if (str1[idx] > str2[idx] || strlen(str1) > strlen(str2))
        return 1;
    else if (str1[idx] < str2[idx] || strlen(str2) < strlen(str2))
        return -1;
    else if (str1[idx] == str2[idx])
    {
        idx++;
        return compare(str1, str2);
    }
    return -1;
}
int main()
{
    char word1[100];
    char word2[100];
    scanf("%s", word1);
    scanf("%s", word2);
    printf("%d", compare(word1, word2));
    return 0;
}