#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
int main()
{
    char a[1000] = { 0 };
    char b[1000] = { 0 };
    char c[1000] = { 0 };
    char* ret = NULL;
    gets(a);
    gets(b);
    for (ret = strtok(a, b);ret != NULL;ret = strtok(NULL, b))
    {
        strcat(c, ret);
    }
    printf("%s", c);
    return 0;
}
