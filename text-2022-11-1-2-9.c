#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    if (0 < a && a < 10000 && 0 < b && b < 10000)
    {
        printf("%d %d", a / b, a % b);
    }
    return 0;
}