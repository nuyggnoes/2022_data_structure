#include <stdio.h>
#include <string.h>
int main()
{
    char input[10000];
    // scanf("%s", input);
    fgets(input, 10000, stdin);
    printf("$ %s : %lu", input, strlen(input));
    return 0;
}