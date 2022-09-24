#include <stdio.h>

int main(void)
{

    int n = 10;

    for (int i = 0; i < n; i++)
    {

        for (int j = n; j > 1 + i; j--)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("*");
        }
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}