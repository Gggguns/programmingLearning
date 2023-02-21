#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int fac(int num)
{
    if (0 == num)
        return 1;
    else if (1 == num)
        return 1;
    else
        return fac(num - 1) * num;
}
int C(int dou, int one)
{
    int min = dou, ret = 0, sum = 0;
    long mul = 1;
    if (one < dou)
        min = one;
    ret = fac(min);
    sum = dou + one;
    while (min)
    {
        mul = mul * sum;
        sum--;
        min--;
    }
    return mul / ret;
}
int main() {
    int num = 0, sum = 0, a = 0, b = 0, ret = 0;
    scanf("%d", &num);
    a = num / 2;
    while (a)
    {
        ret = C(a, num - a * 2);
        sum = sum + ret;
        a--;
    }
    printf("%d", sum + 1);
    return 0;
}