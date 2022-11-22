#include <stdio.h>
#include <string.h>
int main()
{
    char s[10];
    fgets(s, 10, stdin);
    // for (int i = 0; i < strlen(s); i++)
    // {
    //     if (s[i] == '\n')
    //         s[i] = '\0';
    // }
    printf("%s\n", s);
    if (strcmp(s, "abcde\n") == 0)
        printf("hi");
    return 0;
}