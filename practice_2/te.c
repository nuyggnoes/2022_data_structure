#include <stdio.h>
#include <string.h>
int main()
{
    char *v[10];
    char input[10];
    int *tmp;
    int n = 0;
    while (n < 4 && scanf("%s", input) != EOF)
    {
        v[n] = strdup(input);
        n++;
    }
    // tmp = *v[1];
    // v[1] = v[2];
    // v[2] = strdup(&tmp);
    // tmp = *v[1];
    printf("%s", v[1]);
    return 0;
}