// 테스트 데이터를 모두 통과했습니다.
#include <stdio.h>
#include <string.h>
#define LEN 100
int main()
{
    FILE *fp = fopen("sample.html", "r");
    FILE *fw = fopen("correctsample.txt", "w");
    if (fp == NULL)
    {
        return 0;
    }
    char buf[LEN];
    while (fgets(buf, LEN, fp) != NULL)
    {
        for (int i = 0; i < strlen(buf); i++)
        {
            if (buf[i] == '<')
            {
                while (buf[i] != '>')
                {
                    i++;
                    continue;
                }
                continue;
            }
            fprintf(fw, "%c", buf[i]);
        }
    }
    fclose(fp);
    fclose(fw);
    return 0;
}