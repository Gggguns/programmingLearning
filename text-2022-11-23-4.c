#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void* e1, const void* e2)
{
    return *(int*)e1 - *(int*)e2;
}
int main() {
    int arr1[2000] = { 0 }, arr2[1000] = { 0 };
    int n = 0, m = 0, i = 0, judge = 0;
    scanf("%d%d", &n, &m);
    for (i = 0;i < n;i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (i = 0;i < m;i++)
    {
        scanf("%d", &arr2[i]);
    }
    for (i = 0;i < m;i++)
    {
        arr1[n + i] = arr2[i];
    }
    qsort(arr1, m + n, sizeof(arr1[0]), cmp);
    for (i = 0;i < m + n;i++)
    {
        printf("%d ", arr1[i]);
    }
    return 0;
}