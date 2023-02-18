#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int n = 0, a[10][10] = { 0 }, i = 0, j = 0, flat = 1;
    scanf("%d", &n);
    for (i = 0;i < n;i++)
    {
        for (j = 0;j < n;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    flat = 1;
    for (i = 0;i < n;i++)
    {
        for (j = 0;j < i;j++)
        {
            if (a[i][j])
            {
                flat = 0;
                break;
            }
        }
        if (flat == 0)
            break;
    }
    if (1 == flat)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}