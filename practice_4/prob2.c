#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main()
{
    FILE *fp = fopen("input.txt", "r");
    int *input[10];

    if (fp == NULL)
    {
        return 0;
    }
    int n = fgetc(fp) - 48;
    int buf, idx = 0;
    while (fscanf(fp, "%d", &buf) != EOF)
    {
        int data[4] = {
            0,
        };
        for (int i = 0; i < n; i++)
        {
            data[i] = buf;
        }
        input[idx] = strdup(data);
        idx++;
    }
    fclose(fp);
    return 0;
}