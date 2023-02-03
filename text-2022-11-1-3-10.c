#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    int gra;
    while ((scanf("%d", &gra)) != EOF)
    {
        if (90 <= gra && gra <= 100)
            printf("Perfect\n");
    }
    return 0;
}