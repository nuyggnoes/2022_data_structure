#include <stdio.h>
#include <string.h>
void sort(char arr[], int n);
int main()
{
    int n;
    char input[20];
    scanf("%d", &n);
    char *data[100];
    int idx = 0;
    while (idx < n)
    {
        scanf("%s", input);
        data[idx] = strdup(input);
        idx++;
    }
    sort(data, n);
    return 0;
}
void sort(char arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i < n - 1; j++)
        {
            if (strlen(arr[j]) > strlen(arr[j + 1]))
            {
                char *tmp;
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]);
    }
}