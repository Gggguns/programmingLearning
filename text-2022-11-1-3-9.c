#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    int gra;
    while ((scanf("%d", &gra)) != EOF)
    {
        if (60 <= gra)
            printf("Pass\n");
        else
            printf("Fail\n");
    };
    return 0;
}