#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//—≠ª∑strlen
size_t my_strlen1(const char* str)
{ 
	int count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return count;
}
//÷∏’Î-÷∏’Î
size_t my_strlen2(const char* str)
{
	char* end = str;
	while (*end)
	{
		end++;
	}
	return end - str;
}
//µ›πÈ
size_t my_strlen3(const char* str)
{
	if (!*str)
		return 0;
	else
		return 1 + my_strlen3(str + 1);
}
int main()
{
	char arr[] = "ajncjnascjnakjncja";
	printf("%u\n", strlen(arr));
	printf("%u\n", my_strlen1(arr));
	printf("%u\n", my_strlen2(arr));
	printf("%u\n", my_strlen3(arr));
	return 0;
}