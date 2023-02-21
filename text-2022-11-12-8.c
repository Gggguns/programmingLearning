#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    int year = 0, month = 0;
    while ((scanf("%d%d", &year, &month) != EOF))
    {
        switch (month)
        {
        case 1:case 3:
        case 5:case 7:
        case 8:case 10:
        case 12:printf("%d", 31);break;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                printf("%d", 29);
            else
                printf("%d", 28);break;
        default:
            printf("%d", 30);break;
        }
        printf("\n");
    }
    return 0;
}