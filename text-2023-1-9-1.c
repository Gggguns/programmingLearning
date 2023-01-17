#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//Ñ­»·
int my_strlen1(const char* str)
{
	int ret=0;
	while (*str)
	{
		str++;
		ret++;
	}
	return ret; 
}
//µİ¹é
int my_strlen2(const char* str)
{
	if (*str)
		return 1 + my_strlen2(str + 1);
	else
		return 0;
	
}
//Ö¸Õë-Ö¸Õë
int my_strlen3(const char* str)
{
	const char* end = str;
	while (*str)
	{
		end++;
	}
	return (*end) - (*str);
}
int main()
{
	char arr1[] = "jkdsvn";
	char arr2[] = "jkdsvn";
	char arr3[] = "jkdsvn";
	printf("%u ", strlen(arr1));
	printf("%d\n", my_strlen1(arr1));
	printf("%u ", strlen(arr2));
	printf("%d\n", my_strlen1(arr2));
	printf("%u ", strlen(arr3));
	printf("%d\n", my_strlen1(arr3));
}