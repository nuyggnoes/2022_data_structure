// 테스트 데이터를 모두 통과했습니다.
#include <stdio.h>
#include <string.h>
#define LENGTH 100
int n;
void show(int arr[][100], int len);
void colmax(int arr[][100], int len);
void colmin(int arr[][100], int len);
void rowmax(int arr[][100], int len);
void rowmin(int arr[][100], int len);
void slice(int arr[][100], int len, int x, int p, int y, int q);
int main()
{
    FILE *fp = fopen("data.mat.txt", "r");
    int data[LENGTH][LENGTH];
    char ord[15];
    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(fp, "%d", &data[i][j]);
        }
    }
    while (1)
    {
        printf("$ ");
        char *ptr = fgets(ord, LENGTH, stdin);
        if (ptr == NULL)
        {
            break;
        }
        ord[strlen(ord) - 1] = '\0';
        if (strcmp(ord, "show") == 0)
        {
            show(data, n);
        }
        else if (strcmp(ord, "colmax") == 0)
        {
            colmax(data, n);
        }
        else if (strcmp(ord, "colmin") == 0)
        {
            colmin(data, n);
        }
        else if (strcmp(ord, "rowmax") == 0)
        {
            rowmax(data, n);
        }
        else if (strcmp(ord, "rowmin") == 0)
        {
            rowmin(data, n);
        }
        else if (strncmp(ord, "slice", 5) == 0)
        {
            slice(data, n, ord[6], ord[8], ord[10], ord[12]);
        }
        else if (strcmp(ord, "exit") == 0)
        {
            break;
        }
    }
    fclose(fp);
    return 0;
}
void show(int arr[][100], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
void colmax(int arr[][100], int len)
{
    int max = arr[0][0];
    for (int i = 0; i < len; i++)
    {
        max = arr[0][i];
        for (int j = 0; j < len; j++)
        {
            if (arr[j][i] > max)
            {
                max = arr[j][i];
            }
        }
        printf("%d ", max);
    }
    printf("\n");
}
void colmin(int arr[][100], int len)
{
    int min = arr[0][0];
    for (int i = 0; i < len; i++)
    {
        min = arr[0][i];
        for (int j = 0; j < len; j++)
        {
            if (arr[j][i] < min)
            {
                min = arr[j][i];
            }
        }
        printf("%d ", min);
    }
    printf("\n");
}
void rowmax(int arr[][100], int len)
{
    int max = arr[0][0];
    for (int i = 0; i < len; i++)
    {
        max = arr[i][0];
        for (int j = 0; j < len; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
        printf("%d ", max);
    }
    printf("\n");
}
void rowmin(int arr[][100], int len)
{
    int min = arr[0][0];
    for (int i = 0; i < len; i++)
    {
        min = arr[i][0];
        for (int j = 0; j < len; j++)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
            }
        }
        printf("%d ", min);
    }
    printf("\n");
}
void slice(int arr[][100], int len, int x, int p, int y, int q)
{
    x -= 48;
    p -= 48;
    y -= 48;
    q -= 48;
    for (int i = x; i < len; i += p)
    {
        for (int j = y; j < len; j += q)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}