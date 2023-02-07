#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int i = 0, sum = 0;
    scanf("%d", &i);
    do
    {
        sum = sum + i;
        i--;
    } while (i);
    printf("%d", sum);
    return 0;
}