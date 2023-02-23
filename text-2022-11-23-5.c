#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    int arr[50] = { 0 };
    int n = 0, i = 0, flat = 1, juage1 = 0, juage2 = 0;
    scanf("%d", &n);
    for (i = 0;i < n;i++)
    {
        scanf("%d", &arr[i]);
        if (i && i % 2 == 1)
        {
            if (arr[i - 1] < arr[i])
            {
                juage1 = 1;
            }
            else
            {
                juage1 = -1;
            }
        }
        if (i && i % 2 == 0)
        {
            if (arr[i - 1] < arr[i])
            {
                juage2 = 1;
            }
            else
            {
                juage2 = -1;
            }
        }
        if (2 <= i && (juage2 != juage1))
        {
            flat = 0;
            printf("unsorted");
            break;
        }
    }
    if (flat == 1)
        printf("sorted");
    return 0;
}