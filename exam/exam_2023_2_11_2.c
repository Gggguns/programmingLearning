#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
int check_ch(char* a, char* b)
{
    while (*b)
    {
        if (*b == *a)
            return 1;
        b++;
    }
    return 0;
}
void dele(char* s1)
{
    int len = strlen(s1);
    int i = 0;
    while (i < len)
    {
        s1[i] = s1[i + 1];
        i++;
    }
}
int main()
{
    char a[1000] = { 0 };
    char b[1000] = { 0 };
    int ret;
    char* s1 = a;
    gets(a);
    gets(b);
    while (*s1)
    {
        ret = check_ch(s1, b);
        if (ret == 1)
        {
            dele(s1);
            s1--;
        }
        s1++;
    }
    printf("%s", a);
    return 0;
}