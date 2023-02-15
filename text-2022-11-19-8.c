#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void Reverse(char* arr)
{
    char tmp;
    int len = strlen(arr);
    tmp = *arr;
    *arr = *(arr + len - 1);
    *(arr + len - 1) = '\0';
    if (2 < len)
        Reverse(arr + 1);
    *(arr + len - 1) = tmp;
}
int main()
{
    char arr[10001];
    gets(arr);
    Reverse(arr);
    puts(arr);
    return 0;
}