#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char s[15];
    char *data[3];
    int i = 0;
    gets(s);
    char *ptr = strtok(s, " ");
    while (ptr != NULL)
    {
        data[i] = strdup(ptr);
        i++;
        ptr = strtok(NULL, " ");
    }
    for (int k = 0; k < 3; k++)
    {
        printf("%s\n", data[k]);
    }
    return 0;
}