#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void Add_comma(int num)
{
    if (num < 1000)
        printf("%d", num);
    else
    {
        Add_comma(num / 1000);
        printf(",%03d", num % 1000);
    }
}
int main()
{
    int num;
    scanf("%d", &num);
    Add_comma(num);
    return 0;
}
