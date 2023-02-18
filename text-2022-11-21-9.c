#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int n = 0, m = 0, i = 0, j = 0, flat = 0;
    int arr1[10][10] = { 0 }, arr2[10][10] = { 0 };
    scanf("%d%d", &n, &m);
    for (i = 0;i < n;i++)
    {
        for (j = 0;j < m;j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
    for (i = 0;i < n;i++)
    {
        for (j = 0;j < m;j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }
    flat = 1;
    for (i = 0;i < n;i++)
    {
        for (j = 0;j < m;j++)
        {
            if (arr1[i][j] != arr2[i][j])
            {
                flat = 0;
                break;
            }
        }
        if (flat == 0)
            break;
    }
    if (flat == 1)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}