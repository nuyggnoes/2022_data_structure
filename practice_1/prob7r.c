#include <stdio.h>
#include <string.h>
#define MAX 100
int main()
{
    int n;
    char *data[MAX];
    char word[MAX];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", word);
        data[i] = strdup(word);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%s\n", data[i]);
    // }
    
    return 0;
}