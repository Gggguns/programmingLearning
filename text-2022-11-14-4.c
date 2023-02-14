#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int arr[10][10] = { 0 };
    int N = 0, M = 0, i = 0, j = 0, sum = 0;
    scanf("%d%d", &N, &M);
    for (i = 0;i < N;i++)
    {
        for (j = 0;j < M;j++)
        {
            scanf("%d", &arr[i][j]);
            if (0 < arr[i][j])
                sum = sum + arr[i][j];
        }
    }
    printf("%d", sum);
    return 0;
}