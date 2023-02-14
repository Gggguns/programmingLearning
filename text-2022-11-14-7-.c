#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int dele(int* arr, int N, int a)
{
    int i = 0, j = 0;
    for (i = 0;i < N;i++)
    {
        if (arr[i] == a)
        {
            for (j = i;j < N - 1;j++)
            {
                arr[j] = arr[j + 1];
            }
            N--;
            i--;
        }
    }
    return N;
}
int main()
{
    int arr[50] = { 0 };
    int N = 0, i = 0, a = 0, ret = 0;
    scanf("%d", &N);
    for (i = 0;i < N;i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &a);
    ret = dele(arr, N, a);
    for (i = 0;i < ret;i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}