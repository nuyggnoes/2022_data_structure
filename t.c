#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *revert(char *a)
{
    char reversed[20];
    int i, j;
    for (i = 0, j = strlen(a) - 1; j >= 0; i++, j--)
        reversed[i] = a[j];
    reversed[strlen(a)] = '\0';
    return strdup(reversed);
}

int main()
{
    char str[] = "Enjoy Exam";
    char *reversed = revert(str);
    printf("%s\n", reversed);
    return 0;
}