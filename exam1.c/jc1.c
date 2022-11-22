#pragma warning(disable : 4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int main()
{

    char *temp1;
    char *temp2;
    char M[20];
    char *N[MAX];

    for (int i = 0; i < MAX; i++)
    {

        scanf("%s", M);

        if (strcmp(M, "exit") == 0)
        {
            return 0;
        }
        else
        {

            N[i] = strdup(M);

            for (int j = 0; j < i; j++)
            {
                for (int k = 0; k < i - j; k++)
                {
                    if (strlen(N[k]) > strlen(N[k + 1]))
                    {
                        temp1 = N[k];
                        N[k] = N[k + 1];
                        N[k + 1] = temp1;
                    }
                }
            }
            for (int j = 0; j < i; j++)
            {
                for (int k = 0; k < i - j; k++)
                {
                    if (strlen(N[k]) == strlen(N[k + 1]))
                    {
                        if (strcmp(N[k], N[k + 1]) > 0)
                        {
                            temp2 = N[k];
                            N[k] = N[k + 1];
                            N[k + 1] = temp2;
                        }
                    }
                }
            }
            for (int j = 0; j <= i; j++)
            {
                printf("%s ", N[j]);
            }
        }
        printf("\n");
    }
    return 0;
}