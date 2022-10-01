// 테스트 데이터를 모두 통과했습니다.
#include <stdio.h>
#include <math.h>
int main()
{
    FILE *fp = fopen("input.txt", "r");
    int n;
    int input;
    int num[100][100];
    double data1[10][10];
    double data2[10][10];
    if (fp == NULL)
    {
        return 0;
    }
    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(fp, "%d", &input);
            num[i][j] = input;
        }
    }
    fclose(fp);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            data1[0][i] += num[i][j];
            data2[0][i] += num[j][i];
        }
        data1[0][i] /= n;
        data2[0][i] /= n;
    }
    double sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 = 0;
        sum2 = 0;
        for (int j = 0; j < n; j++)
        {
            sum1 += pow((num[i][j] - data1[0][i]), 2);
            sum2 += pow((num[j][i] - data2[0][i]), 2);
        }
        data1[1][i] = sqrt(sum1 / n);
        data2[1][i] = sqrt(sum2 / n);
    }
    int k = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", num[i][j]);
        }
        printf("%0.2lf ", data1[0][i]);
        printf("%0.2lf ", data1[k][i]);
        printf("\n");
    }
    for (int i = 0; i < n; i++)
    {
        printf("%0.2lf ", data2[0][i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%0.2lf ", data2[1][i]);
    }
    return 0;
}