#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int M;
    scanf("%d", &M);
    if (1 <= M && M <= 100000)
    {
        if (M % 5 == 0)
            printf("YES");
        else
            printf("NO");
    }
    return 0;
}