#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    float arr[5][6], sum;
    int i, j;
    for (i = 0;i < 5;i++)
    {
        for (j = 0, sum = 0;j < 5;j++)
        {
            scanf("%f", &arr[i][j]);
            sum = sum + arr[i][j];
        }
        arr[i][5] = sum;
    }
    for (i = 0;i < 5;i++)
    {
        for (j = 0;j < 6;j++)
        {
            printf("%.1f ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}