#include <stdio.h>
#include <string.h>
#include <limits.h>
int main()
{
    FILE *fp;
    char c;
    char *data[100000];
    char word[100];
    int idx = 0;
    fp = fopen("harry.txt", "r");
    while (!feof(fp))
    {
        fscanf(fp, "%s", word);
        data[idx] = word;
        idx++;
    }
    printf("%s", data[0]);
    fclose(fp);
    return 0;
}
//  int a = 0;
//     for (a = 0; !feof(fp); a++)
//     {
//         name = (char*)malloc(sizeof(char) * MAX);
//         fscanf(fp, "%s", name);
//         word[a] = name;
//     }
//     a--;