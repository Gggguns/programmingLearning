#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void Base_convertion(int num, int ba)
{
    if (num < ba)
    {
        if (num < 10)
            printf("%c", num + '0');
        else
            printf("%c", num - 10 + 'a');
    }
    else
    {
        Base_convertion(num / ba, ba);
        if ((num % ba) < 10)
            printf("%c", num % ba + '0');
        else
            printf("%c", num % ba - 10 + 'a');
    }
}
int main()
{
    int num = 0, ba = 10;
    scanf("%d", &ba);
    scanf("%d", &num);
    if (num < ba)
        printf("%c", num + '0');
    else
    {
        Base_convertion(num, ba);
    }
    return 0;
}