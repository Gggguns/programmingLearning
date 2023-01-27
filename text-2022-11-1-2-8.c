#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int x;
    int y;
    scanf("%d", &x);
    if (-10000 < x && x < 10000)
    {
        if (0 == x)
        {
            y = 0;
            printf("%d", y);
        }

        else if (0 < x)
        {
            y = -1;
            printf("%d", y);
        }
        else
        {
            y = 1;
            printf("%d", y);
        }
    }
    return 0;
}