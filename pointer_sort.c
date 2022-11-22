#include <stdio.h>
void func(int *ptra, int *ptrb)
{
    int tmp;
    tmp = *ptrb;
    *ptrb = *ptra;
    *ptra = tmp;
}
int main()
{
    int a = 3, b = 1, c = 2;

    if (a > b)
    {
        func(&a, &b);
    }
    if (b > c)
    {
        func(&b, &c);
    }
    if (a > b)
    {
        func(&a, &b);
    }
    printf("%d %d %d\n", a, b, c);
    return 0;
}