#include <stdio.h>
#include <string.h>
int main()
{
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