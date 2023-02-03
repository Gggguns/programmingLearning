#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    int num;
    while ((scanf("%d", &num)) != EOF)
    {
        if (num % 2 == 0)
            printf("Even\n");
        else
            printf("Odd\n");
    };
    return 0;
}