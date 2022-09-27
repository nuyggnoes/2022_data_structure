#include <stdio.h>
int main()
{
    int n, input;
    int data[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input);
        data[i] = input;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (data[i] > data[j])
                ans++;
        }
    }
    printf("%d", ans);
    return 0;
}