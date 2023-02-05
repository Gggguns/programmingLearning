#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    float t;
    while ((scanf("%d", &t)) != EOF)
    {
        if (t > 0)
            printf("%d\n", 1);
        else if (t == 0)
            printf("%.1F\n", 0.5);
        else
            printf("%d\n", 0);
    }
    return 0;
}