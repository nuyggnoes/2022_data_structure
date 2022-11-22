#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(char *word, int st, int len)
{
    if (len < 2)
        return true;
    else if (word[st] != word[len - 1])
        return false;
    else
        return is_palindrome(word, st + 1, len - 2);
}
int main()
{
    char word[100];
    scanf("%s", word);
    int start = 0;
    int len = strlen(word);
    if (is_palindrome(word, start, len))
        printf("Yes");
    else
        printf("No");
    return 0;
}