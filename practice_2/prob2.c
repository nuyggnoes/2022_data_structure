#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    int c;
    fp = fopen("harry.txt", "r");

    while ((c = fgetc(fp)) != EOF)
    {
        putchar(c);
    }

    fclose(fp);

    return 0;
}