#include <stdio.h>
#include <string.h>
int main()
{
    char input[10000];
    // scanf("%s", input);
    gets(input);
    printf("$ %s : %lu", input, strlen(input));
    return 0;
}