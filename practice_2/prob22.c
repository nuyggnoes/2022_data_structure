#include <stdio.h>
#include <string.h>
#include <limits.h>
#define MAX_LONG 2, 147, 483, 647
int main()
{
    int i_max = INT_MAX;
    int i = 0;
    char d[] = "Block D Masks";
    char *data[3];
    char *ptr = strtok(d, " ");
    while (ptr != NULL)
    {
        data[i] = strdup(ptr);
        ptr = strtok(NULL, " ");
        i++;
    }
    for (int j = 0; j < 3; j++)
    {
        printf("%s\n", data[j]);
    }
    return 0;
}