#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    int n1, n2;
    char c, d;
    do
    {
        scanf("%d", &n1);
        d = getchar();
        if (d == ' ')
        {
            scanf("%d", &n2); 
            if (n1 > n2)
                printf("%d>%d\n", n1, n2);
            else if (n1 == n2)
                printf("%d=%d\n", n1, n2);
            else
                printf("%d<%d\n", n1, n2);
            c = getchar();
        }
        else
            break;

    } while (c == '\n');
    return 0;
}