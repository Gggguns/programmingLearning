#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    int count;
    while ((scanf("%d", &count)) != EOF)
    {
        while (count--)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}