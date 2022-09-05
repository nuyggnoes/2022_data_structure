#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
    int n, input, k, idx, min = INT_MAX;
    int data[100], num[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input);
        data[i] = input;
    }
    scanf("%d", &k);
    for (int j = 0; j < n; j++)
    {
        num[j] = abs(data[j] - k);
        if (abs(data[j] - k) < min)
        {
            min = abs(data[j] - k);
            idx = j;
        }
    }
    printf("%d", data[idx]);
    return 0;
}